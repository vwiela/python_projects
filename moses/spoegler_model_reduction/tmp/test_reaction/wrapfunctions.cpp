#include "amici/model.h"
#include "wrapfunctions.h"
#include "test_reaction.h"

namespace amici {
namespace generic_model {

std::unique_ptr<amici::Model> getModel() {
    return std::unique_ptr<amici::Model>(
        new amici::model_test_reaction::Model_test_reaction());
}


} // namespace generic_model

} // namespace amici
