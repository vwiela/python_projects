#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_test_reaction {

static constexpr std::array<sunindextype, 3> dwdp_rowvals_test_reaction_ = {
    0, 1, 2
};

void dwdp_rowvals_test_reaction(SUNMatrixWrapper &dwdp){
    dwdp.set_indexvals(gsl::make_span(dwdp_rowvals_test_reaction_));
}
} // namespace model_test_reaction
} // namespace amici
