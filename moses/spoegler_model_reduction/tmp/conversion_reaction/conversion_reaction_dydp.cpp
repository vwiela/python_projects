#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "conversion_reaction_x.h"
#include "conversion_reaction_p.h"

namespace amici {
namespace model_conversion_reaction {

void dydp_conversion_reaction(realtype *dydp, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const int ip, const realtype *w, const realtype *dtcldp){
    switch(ip) {
        case 0:
            dydp[2] = 1;
            break;
        case 1:
            dydp[4] = 1;
            break;
        case 2:
            dydp[3] = 1;
            break;
    }
}

} // namespace model_conversion_reaction
} // namespace amici
