#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "test_reaction_x.h"
#include "test_reaction_p.h"
#include "test_reaction_w.h"

namespace amici {
namespace model_test_reaction {

void w_test_reaction(realtype *w, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *tcl){
    flux_R2 = 9.9999999999999998e-13*A*R2_k2;  // w[0]
    flux_R3 = 9.9999999999999998e-13*A*B*R3_k3;  // w[1]
    flux_R1 = 9.9999999999999998e-13*R1_k1;  // w[2]
}

} // namespace model_test_reaction
} // namespace amici
