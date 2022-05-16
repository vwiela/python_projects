#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Spoegler_conversionReaction_p.h"
#include "Spoegler_conversionReaction_y.h"
#include "Spoegler_conversionReaction_sigmay.h"
#include "Spoegler_conversionReaction_my.h"

namespace amici {
namespace model_Spoegler_conversionReaction {

void Jy_Spoegler_conversionReaction(realtype *Jy, const int iy, const realtype *p, const realtype *k, const realtype *y, const realtype *sigmay, const realtype *my){
    switch(iy) {
        case 0:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yA, 2)) + 0.5*std::pow(-myA + yA, 2)/std::pow(sigma_yA, 2);
            break;
        case 1:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yB, 2)) + 0.5*std::pow(-myB + yB, 2)/std::pow(sigma_yB, 2);
            break;
        case 2:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yCell, 2)) + 0.5*std::pow(-myCell + yCell, 2)/std::pow(sigma_yCell, 2);
            break;
    }
}

} // namespace model_Spoegler_conversionReaction
} // namespace amici
