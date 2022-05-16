#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "test_reaction_p.h"
#include "test_reaction_sigmay.h"

namespace amici {
namespace model_test_reaction {

void sigmay_test_reaction(realtype *sigmay, const realtype t, const realtype *p, const realtype *k){
    sigma_yA = 1.0;  // sigmay[0]
    sigma_yB = 1.0;  // sigmay[1]
    sigma_yCell = 1.0;  // sigmay[2]
}

} // namespace model_test_reaction
} // namespace amici
