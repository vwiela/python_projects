#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_Spoegler_conversionReaction {

static constexpr std::array<sunindextype, 4> dxdotdp_explicit_colptrs_Spoegler_conversionReaction_ = {
    0, 1, 3, 5
};

void dxdotdp_explicit_colptrs_Spoegler_conversionReaction(SUNMatrixWrapper &dxdotdp_explicit){
    dxdotdp_explicit.set_indexptrs(gsl::make_span(dxdotdp_explicit_colptrs_Spoegler_conversionReaction_));
}
} // namespace model_Spoegler_conversionReaction
} // namespace amici
