#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "noisy_conversion_reaction_p.h"
#include "noisy_conversion_reaction_sigmay.h"

namespace amici {
namespace model_noisy_conversion_reaction {

void sigmay_noisy_conversion_reaction(realtype *sigmay, const realtype t, const realtype *p, const realtype *k){
    sigma_yA = 1.0;  // sigmay[0]
    sigma_yB = 1.0;  // sigmay[1]
    sigma_yModelValue_0 = 1.0;  // sigmay[2]
    sigma_yModelValue_2 = 1.0;  // sigmay[3]
    sigma_yModelValue_1 = 1.0;  // sigmay[4]
    sigma_yCell = 1.0;  // sigmay[5]
}

} // namespace model_noisy_conversion_reaction
} // namespace amici
