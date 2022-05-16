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

void y_test_reaction(realtype *y, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w){
    y[0] = A;
    y[1] = B;
    y[2] = 9.9999999999999998e-13;
}

} // namespace model_test_reaction
} // namespace amici
