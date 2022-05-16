#include "amici/sundials_matrix_wrapper.h"
#include "sundials/sundials_types.h"

#include <array>
#include <algorithm>

namespace amici {
namespace model_ode1_reaction {

static constexpr std::array<std::array<sunindextype, 4>, 3> dJydy_colptrs_ode1_reaction_ = {{
    {0, 1, 1, 1}, 
    {0, 0, 1, 1}, 
    {0, 0, 0, 1}, 
}};

void dJydy_colptrs_ode1_reaction(SUNMatrixWrapper &dJydy, int index){
    dJydy.set_indexptrs(gsl::make_span(dJydy_colptrs_ode1_reaction_[index]));
}
} // namespace model_ode1_reaction
} // namespace amici
