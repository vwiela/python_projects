#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_conversion_reaction {

static constexpr std::array<sunindextype, 4> dxdotdp_explicit_colptrs_conversion_reaction_ = {
    0, 1, 3, 5
};

void dxdotdp_explicit_colptrs_conversion_reaction(SUNMatrixWrapper &dxdotdp_explicit){
    dxdotdp_explicit.set_indexptrs(gsl::make_span(dxdotdp_explicit_colptrs_conversion_reaction_));
}
} // namespace model_conversion_reaction
} // namespace amici
