#include "amici/model.h"
#include "wrapfunctions.h"
#include "ode1_reaction.h"

namespace amici {
namespace generic_model {

std::unique_ptr<amici::Model> getModel() {
    return std::unique_ptr<amici::Model>(
        new amici::model_ode1_reaction::Model_ode1_reaction());
}


} // namespace generic_model

} // namespace amici
