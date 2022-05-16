#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Sp_gler_ConversionReaction_p.h"
#include "Sp_gler_ConversionReaction_y.h"
#include "Sp_gler_ConversionReaction_sigmay.h"
#include "Sp_gler_ConversionReaction_my.h"

namespace amici {
namespace model_Sp_gler_ConversionReaction {

void dJydsigma_Sp_gler_ConversionReaction(realtype *dJydsigma, const int iy, const realtype *p, const realtype *k, const realtype *y, const realtype *sigmay, const realtype *my){
    switch(iy) {
        case 0:
            dJydsigma[0] = 1.0/sigma_observed_B - 1.0*std::pow(-mobserved_B + observed_B, 2)/std::pow(sigma_observed_B, 3);
            break;
    }
}

} // namespace model_Sp_gler_ConversionReaction
} // namespace amici
