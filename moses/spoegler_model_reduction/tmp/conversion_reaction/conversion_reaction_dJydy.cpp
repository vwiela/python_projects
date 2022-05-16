#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "conversion_reaction_p.h"
#include "conversion_reaction_y.h"
#include "conversion_reaction_sigmay.h"
#include "conversion_reaction_my.h"
#include "conversion_reaction_dJydy.h"

namespace amici {
namespace model_conversion_reaction {

void dJydy_conversion_reaction(realtype *dJydy, const int iy, const realtype *p, const realtype *k, const realtype *y, const realtype *sigmay, const realtype *my){
    switch(iy) {
        case 0:
            dJydy[0] = (-1.0*myA + 1.0*yA)/std::pow(sigma_yA, 2);
            break;
        case 1:
            dJydy[0] = (-1.0*myB + 1.0*yB)/std::pow(sigma_yB, 2);
            break;
        case 2:
            dJydy[0] = (-1.0*myModelValue_0 + 1.0*yModelValue_0)/std::pow(sigma_yModelValue_0, 2);
            break;
        case 3:
            dJydy[0] = (-1.0*myModelValue_2 + 1.0*yModelValue_2)/std::pow(sigma_yModelValue_2, 2);
            break;
        case 4:
            dJydy[0] = (-1.0*myModelValue_1 + 1.0*yModelValue_1)/std::pow(sigma_yModelValue_1, 2);
            break;
        case 5:
            dJydy[0] = (-1.0*myCell + 1.0*yCell)/std::pow(sigma_yCell, 2);
            break;
    }
}

} // namespace model_conversion_reaction
} // namespace amici
