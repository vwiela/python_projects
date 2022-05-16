#include "amici/model.h"
#include "wrapfunctions.h"
#include "Spoegler_conversionReaction.h"

namespace amici {
namespace generic_model {

std::unique_ptr<amici::Model> getModel() {
    return std::unique_ptr<amici::Model>(
        new amici::model_Spoegler_conversionReaction::Model_Spoegler_conversionReaction());
}


} // namespace generic_model

} // namespace amici
