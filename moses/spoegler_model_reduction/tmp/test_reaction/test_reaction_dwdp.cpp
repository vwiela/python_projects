#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "test_reaction_x.h"
#include "test_reaction_p.h"
#include "test_reaction_w.h"
#include "test_reaction_dwdp.h"

namespace amici {
namespace model_test_reaction {

void dwdp_test_reaction(realtype *dwdp, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w, const realtype *tcl, const realtype *dtcldp){
    dflux_R2_dR2_k2 = 9.9999999999999998e-13*A;  // dwdp[0]
    dflux_R3_dR3_k3 = 9.9999999999999998e-13*A*B;  // dwdp[1]
    dflux_R1_dR1_k1 = 9.9999999999999998e-13;  // dwdp[2]
}

} // namespace model_test_reaction
} // namespace amici
