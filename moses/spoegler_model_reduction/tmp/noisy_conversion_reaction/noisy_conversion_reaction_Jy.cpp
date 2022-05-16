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

void Jy_noisy_conversion_reaction(realtype *Jy, const int iy, const realtype *p, const realtype *k, const realtype *y, const realtype *sigmay, const realtype *my){
    switch(iy) {
        case 0:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yA, 2)) + 0.5*std::pow(-myA + yA, 2)/std::pow(sigma_yA, 2);
            break;
        case 1:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yB, 2)) + 0.5*std::pow(-myB + yB, 2)/std::pow(sigma_yB, 2);
            break;
        case 2:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yModelValue_0, 2)) + 0.5*std::pow(-myModelValue_0 + yModelValue_0, 2)/std::pow(sigma_yModelValue_0, 2);
            break;
        case 3:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yModelValue_2, 2)) + 0.5*std::pow(-myModelValue_2 + yModelValue_2, 2)/std::pow(sigma_yModelValue_2, 2);
            break;
        case 4:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yModelValue_1, 2)) + 0.5*std::pow(-myModelValue_1 + yModelValue_1, 2)/std::pow(sigma_yModelValue_1, 2);
            break;
        case 5:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yCell, 2)) + 0.5*std::pow(-myCell + yCell, 2)/std::pow(sigma_yCell, 2);
            break;
    }
}

} // namespace model_noisy_conversion_reaction
} // namespace amici
