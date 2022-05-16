#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Spoegler_conversionReaction_x.h"
#include "Spoegler_conversionReaction_p.h"
#include "Spoegler_conversionReaction_dxdotdx_explicit.h"

namespace amici {
namespace model_Spoegler_conversionReaction {

void dxdotdx_explicit_Spoegler_conversionReaction(realtype *dxdotdx_explicit, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w){
    dxdot0_dA = -B*k3 - k2;  // dxdotdx_explicit[0]
    dxdot1_dA = -B*k3 + k2;  // dxdotdx_explicit[1]
    dxdot0_dB = -A*k3;  // dxdotdx_explicit[2]
    dxdot1_dB = -A*k3;  // dxdotdx_explicit[3]
}

} // namespace model_Spoegler_conversionReaction
} // namespace amici
