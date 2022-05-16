#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_test_reaction {

static constexpr std::array<sunindextype, 4> dwdp_colptrs_test_reaction_ = {
    0, 1, 2, 3
};

void dwdp_colptrs_test_reaction(SUNMatrixWrapper &dwdp){
    dwdp.set_indexptrs(gsl::make_span(dwdp_colptrs_test_reaction_));
}
} // namespace model_test_reaction
} // namespace amici
