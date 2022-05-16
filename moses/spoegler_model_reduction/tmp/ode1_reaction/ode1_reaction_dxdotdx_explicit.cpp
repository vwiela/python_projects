#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "ode1_reaction_x.h"
#include "ode1_reaction_p.h"
#include "ode1_reaction_dxdotdx_explicit.h"

namespace amici {
namespace model_ode1_reaction {

void dxdotdx_explicit_ode1_reaction(realtype *dxdotdx_explicit, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w){
    dxdot0_dA = -B*k3 - k2;  // dxdotdx_explicit[0]
    dxdot1_dA = -B*k3 + k2;  // dxdotdx_explicit[1]
    dxdot0_dB = -A*k3;  // dxdotdx_explicit[2]
    dxdot1_dB = -A*k3;  // dxdotdx_explicit[3]
}

} // namespace model_ode1_reaction
} // namespace amici
