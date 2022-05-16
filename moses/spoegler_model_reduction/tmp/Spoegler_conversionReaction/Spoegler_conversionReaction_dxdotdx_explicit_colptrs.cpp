#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_Spoegler_conversionReaction {

static constexpr std::array<sunindextype, 3> dxdotdx_explicit_colptrs_Spoegler_conversionReaction_ = {
    0, 2, 4
};

void dxdotdx_explicit_colptrs_Spoegler_conversionReaction(SUNMatrixWrapper &dxdotdx_explicit){
    dxdotdx_explicit.set_indexptrs(gsl::make_span(dxdotdx_explicit_colptrs_Spoegler_conversionReaction_));
}
} // namespace model_Spoegler_conversionReaction
} // namespace amici
