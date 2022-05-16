#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_Sp_gler_ConversionReaction {

static constexpr std::array<sunindextype, 3> dxdotdx_explicit_colptrs_Sp_gler_ConversionReaction_ = {
    0, 2, 4
};

void dxdotdx_explicit_colptrs_Sp_gler_ConversionReaction(SUNMatrixWrapper &dxdotdx_explicit){
    dxdotdx_explicit.set_indexptrs(gsl::make_span(dxdotdx_explicit_colptrs_Sp_gler_ConversionReaction_));
}
} // namespace model_Sp_gler_ConversionReaction
} // namespace amici
