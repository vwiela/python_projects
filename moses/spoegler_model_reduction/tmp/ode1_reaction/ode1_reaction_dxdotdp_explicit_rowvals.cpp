#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_ode1_reaction {

static constexpr std::array<sunindextype, 5> dxdotdp_explicit_rowvals_ode1_reaction_ = {
    0, 0, 1, 0, 1
};

void dxdotdp_explicit_rowvals_ode1_reaction(SUNMatrixWrapper &dxdotdp_explicit){
    dxdotdp_explicit.set_indexvals(gsl::make_span(dxdotdp_explicit_rowvals_ode1_reaction_));
}
} // namespace model_ode1_reaction
} // namespace amici
