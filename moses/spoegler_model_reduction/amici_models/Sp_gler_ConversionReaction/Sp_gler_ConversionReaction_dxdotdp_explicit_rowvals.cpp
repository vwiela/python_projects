#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_Sp_gler_ConversionReaction {

static constexpr std::array<sunindextype, 5> dxdotdp_explicit_rowvals_Sp_gler_ConversionReaction_ = {
    0, 0, 1, 0, 1
};

void dxdotdp_explicit_rowvals_Sp_gler_ConversionReaction(SUNMatrixWrapper &dxdotdp_explicit){
    dxdotdp_explicit.set_indexvals(gsl::make_span(dxdotdp_explicit_rowvals_Sp_gler_ConversionReaction_));
}
} // namespace model_Sp_gler_ConversionReaction
} // namespace amici
