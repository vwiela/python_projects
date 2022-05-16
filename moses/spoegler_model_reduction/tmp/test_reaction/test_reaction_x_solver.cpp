#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "test_reaction_x_rdata.h"

namespace amici {
namespace model_test_reaction {

void x_solver_test_reaction(realtype *x_solver, const realtype *x_rdata){
    x_solver[0] = A;
    x_solver[1] = B;
}

} // namespace model_test_reaction
} // namespace amici
