#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "ode1_reaction_p.h"
#include "ode1_reaction_y.h"
#include "ode1_reaction_sigmay.h"
#include "ode1_reaction_my.h"
#include "ode1_reaction_dJydy.h"

namespace amici {
namespace model_ode1_reaction {

void dJydy_ode1_reaction(realtype *dJydy, const int iy, const realtype *p, const realtype *k, const realtype *y, const realtype *sigmay, const realtype *my){
    switch(iy) {
        case 0:
            dJydy[0] = (-1.0*myA + 1.0*yA)/std::pow(sigma_yA, 2);
            break;
        case 1:
            dJydy[0] = (-1.0*myB + 1.0*yB)/std::pow(sigma_yB, 2);
            break;
        case 2:
            dJydy[0] = (-1.0*myCell + 1.0*yCell)/std::pow(sigma_yCell, 2);
            break;
    }
}

} // namespace model_ode1_reaction
} // namespace amici
