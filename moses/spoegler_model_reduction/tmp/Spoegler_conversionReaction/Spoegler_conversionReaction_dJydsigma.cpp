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

void dJydsigma_Spoegler_conversionReaction(realtype *dJydsigma, const int iy, const realtype *p, const realtype *k, const realtype *y, const realtype *sigmay, const realtype *my){
    switch(iy) {
        case 0:
            dJydsigma[0] = 1.0/sigma_yA - 1.0*std::pow(-myA + yA, 2)/std::pow(sigma_yA, 3);
            break;
        case 1:
            dJydsigma[1] = 1.0/sigma_yB - 1.0*std::pow(-myB + yB, 2)/std::pow(sigma_yB, 3);
            break;
        case 2:
            dJydsigma[2] = 1.0/sigma_yCell - 1.0*std::pow(-myCell + yCell, 2)/std::pow(sigma_yCell, 3);
            break;
    }
}

} // namespace model_Spoegler_conversionReaction
} // namespace amici
