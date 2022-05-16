#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Sp_gler_ConversionReaction_p.h"
#include "Sp_gler_ConversionReaction_sigmay.h"

namespace amici {
namespace model_Sp_gler_ConversionReaction {

void sigmay_Sp_gler_ConversionReaction(realtype *sigmay, const realtype t, const realtype *p, const realtype *k){
    sigma_observed_B = noiseParameter1_observed_B;  // sigmay[0]
}

} // namespace model_Sp_gler_ConversionReaction
} // namespace amici
