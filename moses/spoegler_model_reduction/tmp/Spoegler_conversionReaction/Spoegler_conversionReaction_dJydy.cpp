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
#include "Spoegler_conversionReaction_dJydy.h"

namespace amici {
namespace model_Spoegler_conversionReaction {

void dJydy_Spoegler_conversionReaction(realtype *dJydy, const int iy, const realtype *p, const realtype *k, const realtype *y, const realtype *sigmay, const realtype *my){
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

} // namespace model_Spoegler_conversionReaction
} // namespace amici
