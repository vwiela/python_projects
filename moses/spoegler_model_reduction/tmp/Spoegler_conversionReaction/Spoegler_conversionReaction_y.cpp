#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "Spoegler_conversionReaction_x.h"
#include "Spoegler_conversionReaction_p.h"

namespace amici {
namespace model_Spoegler_conversionReaction {

void y_Spoegler_conversionReaction(realtype *y, const realtype t, const realtype *x, const realtype *p, const realtype *k, const realtype *h, const realtype *w){
    y[0] = A;
    y[1] = B;
    y[2] = 1.0;
}

} // namespace model_Spoegler_conversionReaction
} // namespace amici
