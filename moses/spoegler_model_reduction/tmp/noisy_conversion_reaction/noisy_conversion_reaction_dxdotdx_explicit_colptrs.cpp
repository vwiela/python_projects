#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_noisy_conversion_reaction {

static constexpr std::array<sunindextype, 3> dxdotdx_explicit_colptrs_noisy_conversion_reaction_ = {
    0, 2, 4
};

void dxdotdx_explicit_colptrs_noisy_conversion_reaction(SUNMatrixWrapper &dxdotdx_explicit){
    dxdotdx_explicit.set_indexptrs(gsl::make_span(dxdotdx_explicit_colptrs_noisy_conversion_reaction_));
}
} // namespace model_noisy_conversion_reaction
} // namespace amici
