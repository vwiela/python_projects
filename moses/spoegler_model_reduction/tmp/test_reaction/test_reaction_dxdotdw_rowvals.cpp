#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_test_reaction {

static constexpr std::array<sunindextype, 5> dxdotdw_rowvals_test_reaction_ = {
    0, 1, 0, 1, 0
};

void dxdotdw_rowvals_test_reaction(SUNMatrixWrapper &dxdotdw){
    dxdotdw.set_indexvals(gsl::make_span(dxdotdw_rowvals_test_reaction_));
}
} // namespace model_test_reaction
} // namespace amici
