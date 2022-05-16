#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_Sp_gler_ConversionReaction {

static constexpr std::array<std::array<sunindextype, 1>, 1> dJydy_rowvals_Sp_gler_ConversionReaction_ = {{
    {0}, 
}};

void dJydy_rowvals_Sp_gler_ConversionReaction(SUNMatrixWrapper &dJydy, int index){
    dJydy.set_indexvals(gsl::make_span(dJydy_rowvals_Sp_gler_ConversionReaction_[index]));
}
} // namespace model_Sp_gler_ConversionReaction
} // namespace amici
