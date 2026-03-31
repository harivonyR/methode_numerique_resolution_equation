#include <stdio.h>
#include "equation.h"
#include "methode_resolution.h"


int main() {

    printf("Resolution de l'équation f(x) = x^3 + x - 1 \n");
    printf("--------------------------------------------------\n\n");
    printf("1) La methode de disection (dichotonie) :\n");

    double a = 0.0;          // debut interval
    double b = 1.0;          // fin intervale
    double tol = 1e-6;       // approximation
    int max_iter = 100;      // maximum iteration
    double root_bisec = bisection_method(a, b, tol, max_iter);
    printf("Solution x = %lf\n\n", root_bisec);

    printf("2) La methode de Newton :\n");
    double x0 = 0.5;         // point de depart pour la methode de Newton
    double root_newton = newton_method(x0, tol, max_iter);
    printf("Solution x = %lf\n\n", root_newton);

    printf("3) La methode de secante :\n");
    double x0_sec = 0.0;     // point de depart pour la methode de secante
    double x1_sec = 1.0;     // point de depart pour la methode de secante
    double root_secante = scecante_method(x0_sec, x1_sec, tol, max_iter);
    printf("Solution X = %lf\n", root_secante);

    return 0;
}