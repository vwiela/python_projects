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

void dydx_noisy_conversion_reaction(realtype *dydx, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w, const realtype *dwdx){
    dydx[0] = 1;
    dydx[7] = 1;
}

} // namespace model_noisy_conversion_reaction
} // namespace amici
