#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "noisy_conversion_reaction_p.h"
#include "noisy_conversion_reaction_y.h"
#include "noisy_conversion_reaction_sigmay.h"
#include "noisy_conversion_reaction_my.h"

namespace amici {
namespace model_noisy_conversion_reaction {

void dJydsigma_noisy_conversion_reaction(realtype *dJydsigma, const int iy, const realtype *p, const realtype *k, const realtype *y, const realtype *sigmay, const realtype *my){
    switch(iy) {
        case 0:
            dJydsigma[0] = 1.0/sigma_yA - 1.0*std::pow(-myA + yA, 2)/std::pow(sigma_yA, 3);
            break;
        case 1:
            dJydsigma[1] = 1.0/sigma_yB - 1.0*std::pow(-myB + yB, 2)/std::pow(sigma_yB, 3);
            break;
        case 2:
            dJydsigma[2] = 1.0/sigma_yModelValue_0 - 1.0*std::pow(-myModelValue_0 + yModelValue_0, 2)/std::pow(sigma_yModelValue_0, 3);
            break;
        case 3:
            dJydsigma[3] = 1.0/sigma_yModelValue_2 - 1.0*std::pow(-myModelValue_2 + yModelValue_2, 2)/std::pow(sigma_yModelValue_2, 3);
            break;
        case 4:
            dJydsigma[4] = 1.0/sigma_yModelValue_1 - 1.0*std::pow(-myModelValue_1 + yModelValue_1, 2)/std::pow(sigma_yModelValue_1, 3);
            break;
        case 5:
            dJydsigma[5] = 1.0/sigma_yCell - 1.0*std::pow(-myCell + yCell, 2)/std::pow(sigma_yCell, 3);
            break;
    }
}

} // namespace model_noisy_conversion_reaction
} // namespace amici
