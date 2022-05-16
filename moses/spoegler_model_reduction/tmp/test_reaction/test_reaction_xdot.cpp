#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "test_reaction_x.h"
#include "test_reaction_p.h"
#include "test_reaction_w.h"
#include "test_reaction_xdot.h"

namespace amici {
namespace model_test_reaction {

void xdot_test_reaction(realtype *xdot, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w){
    xdot0 = 1000000000000.0*flux_R1 - 1000000000000.0*flux_R2 - 1000000000000.0*flux_R3;  // xdot[0]
    xdot1 = 1000000000000.0*flux_R2 - 1000000000000.0*flux_R3;  // xdot[1]
}

} // namespace model_test_reaction
} // namespace amici
