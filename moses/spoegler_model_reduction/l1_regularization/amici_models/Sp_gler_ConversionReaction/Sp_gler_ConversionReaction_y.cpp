#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Sp_gler_ConversionReaction_x.h"
#include "Sp_gler_ConversionReaction_p.h"

namespace amici {
namespace model_Sp_gler_ConversionReaction {

void y_Sp_gler_ConversionReaction(realtype *y, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w){
    y[0] = B;
}

} // namespace model_Sp_gler_ConversionReaction
} // namespace amici
