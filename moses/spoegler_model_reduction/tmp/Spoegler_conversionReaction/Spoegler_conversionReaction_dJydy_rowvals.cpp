#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_Spoegler_conversionReaction {

static constexpr std::array<std::array<sunindextype, 1>, 3> dJydy_rowvals_Spoegler_conversionReaction_ = {{
    {0}, 
    {0}, 
    {0}, 
}};

void dJydy_rowvals_Spoegler_conversionReaction(SUNMatrixWrapper &dJydy, int index){
    dJydy.set_indexvals(gsl::make_span(dJydy_rowvals_Spoegler_conversionReaction_[index]));
}
} // namespace model_Spoegler_conversionReaction
} // namespace amici
