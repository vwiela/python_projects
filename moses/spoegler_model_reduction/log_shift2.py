import os
import importlib

import amici
import matplotlib.pyplot as plt
import numpy as np 
import petab 

import pypesto
import pypesto.optimize as optimize
import pypesto.petab
import pypesto.visualize as visualize

model_name= "Spoegler_conversionReaction"
param_scale= "log10_shift2"


# the yaml file includes all important links to other files
yaml_config ="petab/"+param_scale+"/"+model_name+".yaml"
# create a petab problem
petab_problem = petab.Problem.from_yaml(yaml_config)

# import to amici
importer = pypesto.petab.PetabImporter(petab_problem)
importer.compile_model()

model = importer.create_model()

# model properties
print("Model parameters:", list(model.getParameterIds()), "\n")
print("Model constant parameters:", list(model.getFixedParameterIds()), "\n")
print("Model outputs:    ", list(model.getObservableIds()), "\n")
print("Model states:     ", list(model.getStateIds()), "\n")

# initialize solver and options
solver = importer.create_solver(model)

# enable sensitivities
solver.setSensitivityOrder(amici.SensitivityOrder_first)       
solver.setSensitivityMethod(amici.SensitivityMethod_forward)  
model.requireSensitivitiesForAllParameters()       

# linear objective function
obj_lin = importer.create_objective()

# shifted parameter
eps = 1
def fun(x):
    return obj_lin.get_fval(10**np.array(x)-eps)

def grad(x):
    return obj_lin.get_grad(10**np.array(x)-eps) * 10**np.array(x) * np.log(10)


# new objective function
obj = pypesto.Objective(fun=fun, grad=grad)

# create optimizer object
optimizer = optimize.ScipyOptimizer()

# create problem object
problem = importer.create_problem(obj)

# do the optimization
n_starts = 1000

result = optimize.minimize(
        problem=problem, optimizer=optimizer, n_starts=n_starts, filename=None
)

# print results
best_result=result.optimize_result.as_list("x")[0]["x"]
print('best parameter: ', best_result)
print('best likelihood value: ', problem.objective(best_result))

fvals = result.optimize_result.get_for_key("fval")
fval = np.array(fvals)
fval=fval[fval < 1e2]
visualize.waterfall_lowlevel(fval, scale_y='lin')