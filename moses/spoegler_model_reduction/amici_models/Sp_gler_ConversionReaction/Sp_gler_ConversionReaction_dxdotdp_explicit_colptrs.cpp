#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_Sp_gler_ConversionReaction {

static constexpr std::array<sunindextype, 5> dxdotdp_explicit_colptrs_Sp_gler_ConversionReaction_ = {
    0, 1, 3, 5, 5
};

void dxdotdp_explicit_colptrs_Sp_gler_ConversionReaction(SUNMatrixWrapper &dxdotdp_explicit){
    dxdotdp_explicit.set_indexptrs(gsl::make_span(dxdotdp_explicit_colptrs_Sp_gler_ConversionReaction_));
}
} // namespace model_Sp_gler_ConversionReaction
} // namespace amici
