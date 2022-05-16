#include "amici/symbolic_functions.h"
#include "amici/defines.h"
#include "sundials/sundials_types.h"

#include <gsl/gsl-lite.hpp>
#include <array>
#include <algorithm>

#include "test_reaction_p.h"
#include "test_reaction_y.h"
#include "test_reaction_sigmay.h"
#include "test_reaction_my.h"

namespace amici {
namespace model_test_reaction {

void Jy_test_reaction(realtype *Jy, const int iy, const realtype *p, const realtype *k, const realtype *y, const realtype *sigmay, const realtype *my){
    switch(iy) {
        case 0:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yA, 2)) + 0.5*std::pow(-myA + yA, 2)/std::pow(sigma_yA, 2);
            break;
        case 1:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yB, 2)) + 0.5*std::pow(-myB + yB, 2)/std::pow(sigma_yB, 2);
            break;
        case 2:
            Jy[0] = 0.5*std::log(2*amici::pi*std::pow(sigma_yCell, 2)) + 0.5*std::pow(-myCell + yCell, 2)/std::pow(sigma_yCell, 2);
            break;
    }
}

} // namespace model_test_reaction
} // namespace amici
