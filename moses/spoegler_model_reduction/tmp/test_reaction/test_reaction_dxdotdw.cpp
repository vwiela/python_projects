#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "test_reaction_x.h"
#include "test_reaction_p.h"
#include "test_reaction_w.h"
#include "test_reaction_dxdotdw.h"

namespace amici {
namespace model_test_reaction {

void dxdotdw_test_reaction(realtype *dxdotdw, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w){
    dxdot0_dflux_R2 = -1000000000000.0;  // dxdotdw[0]
    dxdot1_dflux_R2 = 1000000000000.0;  // dxdotdw[1]
    dxdot0_dflux_R3 = -1000000000000.0;  // dxdotdw[2]
    dxdot1_dflux_R3 = -1000000000000.0;  // dxdotdw[3]
    dxdot0_dflux_R1 = 1000000000000.0;  // dxdotdw[4]
}

} // namespace model_test_reaction
} // namespace amici
