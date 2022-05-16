#include "test_reaction.h"
#include <array>

namespace amici {

namespace model_test_reaction {

std::array<const char*, 3> parameterNames = {
    "k2", // p[0]
"k3", // p[1]
"k1", // p[2]
};

std::array<const char*, 0> fixedParameterNames = {
    
};

std::array<const char*, 2> stateNames = {
    "A", // x_rdata[0]
"B", // x_rdata[1]
};

std::array<const char*, 3> observableNames = {
    "A", // y[0]
"B", // y[1]
"Cell", // y[2]
};

std::array<const ObservableScaling, 3> observableScalings = {
    ObservableScaling::lin, // y[0]
ObservableScaling::lin, // y[1]
ObservableScaling::lin, // y[2]
};

std::array<const char*, 3> expressionNames = {
    "flux_R2", // w[0]
"flux_R3", // w[1]
"flux_R1", // w[2]
};

std::array<const char*, 3> parameterIds = {
    "R2_k2", // p[0]
"R3_k3", // p[1]
"R1_k1", // p[2]
};

std::array<const char*, 0> fixedParameterIds = {
    
};

std::array<const char*, 2> stateIds = {
    "A", // x_rdata[0]
"B", // x_rdata[1]
};

std::array<const char*, 3> observableIds = {
    "yA", // y[0]
"yB", // y[1]
"yCell", // y[2]
};

std::array<const char*, 3> expressionIds = {
    "flux_R2", // w[0]
"flux_R3", // w[1]
"flux_R1", // w[2]
};

std::array<int, 2> stateIdxsSolver = {
    0, 1
};

} // namespace model_test_reaction

} // namespace amici
