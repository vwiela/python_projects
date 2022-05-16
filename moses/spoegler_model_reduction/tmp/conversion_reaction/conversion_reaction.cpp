#include "conversion_reaction.h"
#include <array>

namespace amici {

namespace model_conversion_reaction {

std::array<const char*, 3> parameterNames = {
    "k1", // p[0]
"k2", // p[1]
"k3", // p[2]
};

std::array<const char*, 0> fixedParameterNames = {
    
};

std::array<const char*, 2> stateNames = {
    "A", // x_rdata[0]
"B", // x_rdata[1]
};

std::array<const char*, 6> observableNames = {
    "A", // y[0]
"B", // y[1]
"ModelValue_0", // y[2]
"ModelValue_2", // y[3]
"ModelValue_1", // y[4]
"Cell", // y[5]
};

std::array<const ObservableScaling, 6> observableScalings = {
    ObservableScaling::lin, // y[0]
ObservableScaling::lin, // y[1]
ObservableScaling::lin, // y[2]
ObservableScaling::lin, // y[3]
ObservableScaling::lin, // y[4]
ObservableScaling::lin, // y[5]
};

std::array<const char*, 1> expressionNames = {
    "flux_r0", // w[0]
};

std::array<const char*, 3> parameterIds = {
    "k1", // p[0]
"k2", // p[1]
"k3", // p[2]
};

std::array<const char*, 0> fixedParameterIds = {
    
};

std::array<const char*, 2> stateIds = {
    "A", // x_rdata[0]
"B", // x_rdata[1]
};

std::array<const char*, 6> observableIds = {
    "yA", // y[0]
"yB", // y[1]
"yModelValue_0", // y[2]
"yModelValue_2", // y[3]
"yModelValue_1", // y[4]
"yCell", // y[5]
};

std::array<const char*, 1> expressionIds = {
    "flux_r0", // w[0]
};

std::array<int, 2> stateIdxsSolver = {
    0, 1
};

} // namespace model_conversion_reaction

} // namespace amici
