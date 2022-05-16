#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_test_reaction {

static constexpr std::array<sunindextype, 3> dwdx_rowvals_test_reaction_ = {
    0, 1, 1
};

void dwdx_rowvals_test_reaction(SUNMatrixWrapper &dwdx){
    dwdx.set_indexvals(gsl::make_span(dwdx_rowvals_test_reaction_));
}
} // namespace model_test_reaction
} // namespace amici
