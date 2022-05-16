#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_Sp_gler_ConversionReaction {

static constexpr std::array<std::array<sunindextype, 2>, 1> dJydy_colptrs_Sp_gler_ConversionReaction_ = {{
    {0, 1}, 
}};

void dJydy_colptrs_Sp_gler_ConversionReaction(SUNMatrixWrapper &dJydy, int index){
    dJydy.set_indexptrs(gsl::make_span(dJydy_colptrs_Sp_gler_ConversionReaction_[index]));
}
} // namespace model_Sp_gler_ConversionReaction
} // namespace amici
