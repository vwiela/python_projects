#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "noisy_conversion_reaction_x.h"
#include "noisy_conversion_reaction_p.h"

namespace amici {
namespace model_noisy_conversion_reaction {

void y_noisy_conversion_reaction(realtype *y, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w){
    y[0] = A;
    y[1] = B;
    y[2] = k1;
    y[3] = k3;
    y[4] = k2;
    y[5] = 1.0;
}

} // namespace model_noisy_conversion_reaction
} // namespace amici
