#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_Spoegler_conversionReaction {

static constexpr std::array<sunindextype, 4> dxdotdx_explicit_rowvals_Spoegler_conversionReaction_ = {
    0, 1, 0, 1
};

void dxdotdx_explicit_rowvals_Spoegler_conversionReaction(SUNMatrixWrapper &dxdotdx_explicit){
    dxdotdx_explicit.set_indexvals(gsl::make_span(dxdotdx_explicit_rowvals_Spoegler_conversionReaction_));
}
} // namespace model_Spoegler_conversionReaction
} // namespace amici
