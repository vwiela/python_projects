import numpy as np
import pypesto




class l1_regularization:

    """
        inputs:
        model: model defined by petab import
        petab_problem: petab problem
        linear_objective: the objctive function of the problem
        param_scale: 'lin', 'log10_shift' or 'logicle'
        lambda_range: interval where my penalization strength lambda
                      e.g. [10, 100]
        n_lambda: number (integer) of how many penalization strength
                  chosen in the interval lambda range. We use equidistant
                  lambdas
    """

    def __init__(self,
                 model,
                 petab_problem,
                 linear_objective,
                 param_scale,
                 lambda_range,
                 n_lambda):

        self.model = model
        self.petab_problem = petab_problem
        self.importer = pypesto.petab.PetabImporter(petab_problem)
        self.param_scale = param_scale
        self.lambda_range = lambda_range
        self.n_lambda = n_lambda
        self.lin_objective = linear_objective
        self.n_params= len(petab_problem.get_model_parameters())


        # calculate a list of priors corresponding to
        # all penalization strengths
        prior_list = all_priors(petab_problem,
                                priorParameters_list = None,
                                lambda_range = self.lambda_range,
                                n_lambda = self.n_lambda)

        self.prior_list = prior_list

        # for all priors calculate the corresponding objective
        # function and store them in a list
        objective_list = multiple_objective(lin_obj=self.lin_objective,
                                            param_scale = self.param_scale,
                                            prior_list = self.prior_list)

        self.objective_list = objective_list

    # call regularization
    # optimize all objective functions
    def __call__(self,
                 n_starts,
                 x_guesses=None,
                 opt_method=None,
                 opt_options=None,
                 par_names=None,
                 option_stop=False,
                 threshold=None,
                 path=None):

        # if option_stop=True than a parameter smaller than the threshold is
        # set to 0 for all future optimizations

        # optimite multiple objecives
        result_list = multiple_optimization(petab_problem=self.petab_problem,
                                            objective_list=self.objective_list,
                                            n_starts=n_starts,
                                            n_estimate=self.n_estimate,
                                            threshold=threshold,
                                            x_guesses=x_guesses,
                                            par_names=par_names,
                                            path=path)

        return result_list

# ----------------------------------------------------------------------------------------------

# function to generate multiple priors corresponding
# to all the different penalization strnegths

def make_prior(petab_problem, prior_param, scale='lin'): 
  prior_list = []

    # l1 regularization is achieved by using laplacian
    # priors

  for i in range(len(petab_problem.get_model_parameters())):
    priorType = 'laplace'
    priorParameters = prior_param[i]
    priorScale = scale
    prior = pypesto.objective.get_parameter_prior_dict(i, priorType, priorParameters, priorScale)
    prior_list.append(prior)

  return pypesto.objective.NegLogParameterPriors(prior_list)


def all_priors(petab_problem,
                   priorParameters_list=None,
                   lambda_range=None,
                   n_lambda=None):

    lambda_range_log = [np.log10(lambda_range[0]), np.log10(lambda_range[1])]
    lambda_log = -np.linspace(lambda_range_log[0], lambda_range_log[1], n_lambda)

    priorParameters_list = []
    for i in range(0, n_lambda):
        parameters = [[0, 1/10**lambda_log[i]]] * len(petab_problem.get_model_parameters())
         # CHECK whether really to use 1/lambda
        priorParameters_list.append(parameters)

    #print(priorParameters_list)
    prior_list = []

    for par in range(0, n_lambda):
        prior = make_prior(petab_problem, priorParameters_list[par], scale='lin')
        prior_list.append(prior)

    return prior_list


def multiple_objective(lin_obj, param_scale, prior_list):

    # calculate the objective functions for the different priors regarding to the scale

    if param_scale ==  'lin':

     
        objective_list = []
        for prior in range(0, len(prior_list)):
            objective =  pypesto.objective.AggregatedObjective([lin_obj, prior_list[prior]])
            objective_list.append(objective)

        return objective_list

    elif param_scale ==  'log10_shift':

     
        objective_list = []
        for prior in range(0, len(prior_list)):
            unscaled_objective = pypesto.objective.AggregatedObjective([lin_obj, prior_list[prior]])
            f = lambda x: unscaled_objective.get_fval(10**np.array(x)-1)
            g = lambda x: unscaled_objective.get_grad(10**np.array(x)-1) * 10**np.array(x) * np.log(10)
            # new objective function
            objective = pypesto.Objective(fun=f, grad=g)
            objective_list.append(objective)

        return objective_list

    elif param_scale ==  'logicle':

        from LogicleScale import    logicleTransform, \
                            logicleInverseTransform, \
                            function_parameters, \
                            logicleGradient, \
                            logicleInverseGradient

        objective_list = []
        T = 1000
        trans = 1e-5
        for prior in range(0, len(prior_list)):    
            unscaled_objective = pypesto.objective.AggregatedObjective([lin_obj, prior_list[prior]])
            f = lambda x: unscaled_objective.get_fval(logicleInverseTransform(scaled=x, T=T, trans=trans))
            g = lambda x: unscaled_objective.get_grad(logicleInverseTransform(scaled=x, T=T, trans=trans)) * logicleInverseGradient(scaled=x, T=T, trans=trans)
            # new objective function
            objective= pypesto.Objective(fun=f, grad=g)
            objective_list.append(objective)

        return objective_list
    
    else:
        raise  Exception('Parameter scale must be in lin, log10_shift or logicle.')



def multiple_optimization(petab_problem,
                          objective_list,
                          n_starts,
                          importer = None,
                          x_guesses=None,
                          opt_method=None,
                          opt_options=None,
                          par_names=None,
                          option_stop=False,
                          threshold=None,
                          n_estimate=None,
                          path=None):


    result_list = []

    if opt_method is None:
        opt_method = 'L-BFGS-B'

    if threshold is None:
        threshold = 1e-10

    if n_estimate is None:
        n_estimate = len(petab_problem.get_model_parameters())

    if importer is None:
        importer = pypesto.petab.PetabImporter(petab_problem)

    for obj in range(0, len(objective_list)):

        optimizer = pypesto.ScipyOptimizer(method=opt_method)
        optimizer.options = opt_options

        if option_stop:

            problem = importer.create_problem(objective=objective_list[obj],
                                              x_fixed_vals=x_fixed_vals,
                                              x_fixed_indices=x_fixed_indices,
                                              x_guesses=x_guesses)

        else:

            problem = importer.create_problem(objective=objective_list[obj],
                                              x_guesses=x_guesses)

        # do the optimization
        result = pypesto.optimize.minimize(problem=problem,
                                           optimizer=optimizer,
                                           n_starts=n_starts)

        print('result', obj, '=', result)
        print('best result = ', result.optimize_result.as_list('x')[0]['x'])


        # if option_stop=True, than fix the parameters
        if option_stop:
            print('hier')
            # set small values to 0 and fix them
            best_result = result.optimize_result.as_list('x')[0]['x']
            best_result[best_result < threshold] = 0

            x_fixed_indices = np.where(best_result == 0)[0]

            if len(x_fixed_indices):
                x_fixed_vals = [0] * len(x_fixed_indices)

            if len(x_fixed_indices) == n_estimate:
                result_list.append(result)
                break

        # get the best results as startpoints of the next optimization
        x_guesses = []
        for i in range(0, n_starts):
            temp = result.optimize_result.as_list('x')[i]['x']
            if temp is not None:
                x_guesses.append(temp)

        # append result to list
        result_list.append(result)

    return result_list

# compute regularization paths-------------------------------------------------------------------

# the regularization path contains the value of every parameter
# along the penalization strength

def compute_regularization_path(result_list, lambda_range, n_lambda, n_sigma=None):

    # different log10 penalization strengths
    lambda_range_log = np.log10(lambda_range)
    lambdas = -np.linspace(lambda_range_log[0], lambda_range_log[1], n_lambda)[::-1]

    if n_sigma is None:
        n_sigma = 0

    parameter_list = []
    for i in range(0, len(result_list[0].optimize_result.as_list('x')[0]['x']) - n_sigma):
        parameter = []

        for j in range(0, len(result_list)):
            result_list[j].optimize_result.sort()
            parameter.append(result_list[j].optimize_result.as_list('x')[0]['x'][i])

        # add zeros to the end for non optimized results
        j = 0
        while len(result_list) + j < len(lambdas):
            parameter.append(0.0)
            j += 1

        parameter_list.append(parameter)

    return parameter_list


# calculate number of converged points------------------------------------------------------------


def compute_converged_points_single(result, threshold=None):

    # threshold at which two points are assumed to
    # be "equal" (converged)
    if threshold is None:
        threshold = 1e-2

    # get the best result
    best_result = result.optimize_result.as_list('x')[0]['x']

    n_starts = len(result.optimize_result.as_list('x'))

    # compare best result with all other results
    # |best_result - other_result| < threshold
    conv_points = 0
    for i in range(0, n_starts):

        other_result = result.optimize_result.as_list('x')[i]['x']

        if other_result is not None:
            converged = (np.abs((other_result - best_result)) < (threshold * len(other_result))).all()

            if converged:
                conv_points += 1

    return conv_points


def compute_converged_points(result_list, threshold=None):

    convergence_list = []

    for i in range(0, len(result_list)):
        temp = compute_converged_points_single(result=result_list[i], threshold=threshold)

        convergence_list.append(temp)

    return convergence_list

