#include "amici/model.h"
#include "wrapfunctions.h"
#include "conversion_reaction.h"

namespace amici {
namespace generic_model {

std::unique_ptr<amici::Model> getModel() {
    return std::unique_ptr<amici::Model>(
        new amici::model_conversion_reaction::Model_conversion_reaction());
}


} // namespace generic_model

} // namespace amici
