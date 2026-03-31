#include "equation.h"

double f(double x) {
    // cette fonction represente f(x) = x^3 + x - 1
    return x * x * x + x - 1.0;
}

double f_diff(double x){
    // cette fonction represente la derivee de l'equation f, f'(x) = 3x^2 + 1
    return 3 * x * x + 1.0;
}