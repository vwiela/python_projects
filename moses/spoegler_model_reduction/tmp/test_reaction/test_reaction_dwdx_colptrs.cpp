#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_test_reaction {

static constexpr std::array<sunindextype, 3> dwdx_colptrs_test_reaction_ = {
    0, 2, 3
};

void dwdx_colptrs_test_reaction(SUNMatrixWrapper &dwdx){
    dwdx.set_indexptrs(gsl::make_span(dwdx_colptrs_test_reaction_));
}
} // namespace model_test_reaction
} // namespace amici
