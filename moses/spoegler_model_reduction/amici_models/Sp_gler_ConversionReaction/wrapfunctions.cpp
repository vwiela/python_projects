#include "amici/model.h"
#include "wrapfunctions.h"
#include "Sp_gler_ConversionReaction.h"

namespace amici {
namespace generic_model {

std::unique_ptr<amici::Model> getModel() {
    return std::unique_ptr<amici::Model>(
        new amici::model_Sp_gler_ConversionReaction::Model_Sp_gler_ConversionReaction());
}


} // namespace generic_model

} // namespace amici
