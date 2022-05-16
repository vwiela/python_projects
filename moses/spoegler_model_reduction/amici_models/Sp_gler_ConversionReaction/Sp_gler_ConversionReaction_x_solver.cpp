#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Sp_gler_ConversionReaction_x_rdata.h"

namespace amici {
namespace model_Sp_gler_ConversionReaction {

void x_solver_Sp_gler_ConversionReaction(realtype *x_solver, const realtype *x_rdata){
    x_solver[0] = A;
    x_solver[1] = B;
}

} // namespace model_Sp_gler_ConversionReaction
} // namespace amici