#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Sp_gler_ConversionReaction_p.h"

namespace amici {
namespace model_Sp_gler_ConversionReaction {

void dsigmaydp_Sp_gler_ConversionReaction(realtype *dsigmaydp, const realtype t, const realtype *p, const realtype *k, const int ip){
    switch(ip) {
        case 3:
            dsigmaydp[0] = 1;
            break;
    }
}

} // namespace model_Sp_gler_ConversionReaction
} // namespace amici
