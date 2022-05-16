#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "test_reaction_x.h"

namespace amici {
namespace model_test_reaction {

void x_rdata_test_reaction(realtype *x_rdata, const realtype *x, const realtype *tcl){
    x_rdata[0] = A;
    x_rdata[1] = B;
}

} // namespace model_test_reaction
} // namespace amici
