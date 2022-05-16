#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "test_reaction_x.h"
#include "test_reaction_p.h"
#include "test_reaction_w.h"
#include "test_reaction_dwdx.h"

namespace amici {
namespace model_test_reaction {

void dwdx_test_reaction(realtype *dwdx, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w, const realtype *tcl){
    dflux_R2_dA = 9.9999999999999998e-13*R2_k2;  // dwdx[0]
    dflux_R3_dA = 9.9999999999999998e-13*B*R3_k3;  // dwdx[1]
    dflux_R3_dB = 9.9999999999999998e-13*A*R3_k3;  // dwdx[2]
}

} // namespace model_test_reaction
} // namespace amici
