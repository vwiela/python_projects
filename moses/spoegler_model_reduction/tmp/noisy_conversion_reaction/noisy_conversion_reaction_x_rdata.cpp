#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "noisy_conversion_reaction_x.h"

namespace amici {
namespace model_noisy_conversion_reaction {

void x_rdata_noisy_conversion_reaction(realtype *x_rdata, const realtype *x, const realtype *tcl){
    x_rdata[0] = A;
    x_rdata[1] = B;
}

} // namespace model_noisy_conversion_reaction
} // namespace amici
