#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Sp_gler_ConversionReaction_x.h"
#include "Sp_gler_ConversionReaction_p.h"
#include "Sp_gler_ConversionReaction_xdot.h"

namespace amici {
namespace model_Sp_gler_ConversionReaction {

void xdot_Sp_gler_ConversionReaction(realtype *xdot, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w){
    xdot0 = -A*B*k3 - A*k2 + k1;  // xdot[0]
    xdot1 = -A*B*k3 + A*k2;  // xdot[1]
}

} // namespace model_Sp_gler_ConversionReaction
} // namespace amici
