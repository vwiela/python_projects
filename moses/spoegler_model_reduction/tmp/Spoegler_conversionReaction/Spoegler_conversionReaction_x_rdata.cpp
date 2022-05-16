#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Spoegler_conversionReaction_x.h"

namespace amici {
namespace model_Spoegler_conversionReaction {

void x_rdata_Spoegler_conversionReaction(realtype *x_rdata, const realtype *x, const realtype *tcl){
    x_rdata[0] = A;
    x_rdata[1] = B;
}

} // namespace model_Spoegler_conversionReaction
} // namespace amici
