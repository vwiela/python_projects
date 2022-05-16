#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "ode1_reaction_x.h"
#include "ode1_reaction_p.h"

namespace amici {
namespace model_ode1_reaction {

void dydx_ode1_reaction(realtype *dydx, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w, const realtype *dwdx){
    dydx[0] = 1;
    dydx[4] = 1;
}

} // namespace model_ode1_reaction
} // namespace amici
