#include "Sp_gler_ConversionReaction.h"
#include <array>

namespace amici {

namespace model_Sp_gler_ConversionReaction {

std::array<const char*, 4> parameterNames = {
    "k1", // p[0]
"k2", // p[1]
"k3", // p[2]
"noiseParameter1_observed_B", // p[3]
};

std::array<const char*, 0> fixedParameterNames = {
    
};

std::array<const char*, 2> stateNames = {
    "A", // x_rdata[0]
"B", // x_rdata[1]
};

std::array<const char*, 1> observableNames = {
    "", // y[0]
};

std::array<const ObservableScaling, 1> observableScalings = {
    ObservableScaling::lin, // y[0]
};

std::array<const char*, 1> expressionNames = {
    "flux_r0", // w[0]
};

std::array<const char*, 4> parameterIds = {
    "k1", // p[0]
"k2", // p[1]
"k3", // p[2]
"noiseParameter1_observed_B", // p[3]
};

std::array<const char*, 0> fixedParameterIds = {
    
};

std::array<const char*, 2> stateIds = {
    "A", // x_rdata[0]
"B", // x_rdata[1]
};

std::array<const char*, 1> observableIds = {
    "observed_B", // y[0]
};

std::array<const char*, 1> expressionIds = {
    "flux_r0", // w[0]
};

std::array<int, 2> stateIdxsSolver = {
    0, 1
};

} // namespace model_Sp_gler_ConversionReaction

} // namespace amici
