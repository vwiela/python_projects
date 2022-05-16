#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_ode1_reaction {

static constexpr std::array<sunindextype, 4> dxdotdp_explicit_colptrs_ode1_reaction_ = {
    0, 1, 3, 5
};

void dxdotdp_explicit_colptrs_ode1_reaction(SUNMatrixWrapper &dxdotdp_explicit){
    dxdotdp_explicit.set_indexptrs(gsl::make_span(dxdotdp_explicit_colptrs_ode1_reaction_));
}
} // namespace model_ode1_reaction
} // namespace amici
