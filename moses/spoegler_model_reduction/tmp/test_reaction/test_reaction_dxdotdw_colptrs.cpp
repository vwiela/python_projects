#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_test_reaction {

static constexpr std::array<sunindextype, 4> dxdotdw_colptrs_test_reaction_ = {
    0, 2, 4, 5
};

void dxdotdw_colptrs_test_reaction(SUNMatrixWrapper &dxdotdw){
    dxdotdw.set_indexptrs(gsl::make_span(dxdotdw_colptrs_test_reaction_));
}
} // namespace model_test_reaction
} // namespace amici
