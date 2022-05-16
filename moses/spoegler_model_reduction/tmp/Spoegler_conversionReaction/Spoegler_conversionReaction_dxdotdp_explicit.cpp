#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Spoegler_conversionReaction_x.h"
#include "Spoegler_conversionReaction_p.h"
#include "Spoegler_conversionReaction_dxdotdp_explicit.h"

namespace amici {
namespace model_Spoegler_conversionReaction {

void dxdotdp_explicit_Spoegler_conversionReaction(realtype *dxdotdp_explicit, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w){
    dxdot0_dk1 = 1;  // dxdotdp_explicit[0]
    dxdot0_dk2 = -A;  // dxdotdp_explicit[1]
    dxdot1_dk2 = A;  // dxdotdp_explicit[2]
    dxdot0_dk3 = -A*B;  // dxdotdp_explicit[3]
    dxdot1_dk3 = -A*B;  // dxdotdp_explicit[4]
}

} // namespace model_Spoegler_conversionReaction
} // namespace amici
