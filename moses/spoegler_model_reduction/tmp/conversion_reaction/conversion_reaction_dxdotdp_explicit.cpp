#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "conversion_reaction_x.h"
#include "conversion_reaction_p.h"
#include "conversion_reaction_dxdotdp_explicit.h"

namespace amici {
namespace model_conversion_reaction {

void dxdotdp_explicit_conversion_reaction(realtype *dxdotdp_explicit, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w){
    dxdot0_dk1 = 1;  // dxdotdp_explicit[0]
    dxdot0_dk2 = -A;  // dxdotdp_explicit[1]
    dxdot1_dk2 = A;  // dxdotdp_explicit[2]
    dxdot0_dk3 = -A*B;  // dxdotdp_explicit[3]
    dxdot1_dk3 = -A*B;  // dxdotdp_explicit[4]
}

} // namespace model_conversion_reaction
} // namespace amici
