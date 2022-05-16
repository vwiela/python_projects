#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Sp_gler_ConversionReaction_x.h"

namespace amici {
namespace model_Sp_gler_ConversionReaction {

void x_rdata_Sp_gler_ConversionReaction(realtype *x_rdata, const realtype *x, const realtype *tcl){
    x_rdata[0] = A;
    x_rdata[1] = B;
}

} // namespace model_Sp_gler_ConversionReaction
} // namespace amici