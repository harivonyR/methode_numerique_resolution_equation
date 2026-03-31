#include <stdio.h>
#include <math.h>
#include "equation.h"
#include "methode_resolution.h"

double bisection_method(double a, double b, double tol, int max_iter) {
    /*
        la methode de bisection ou dichotonie divise l'intervalle [a, b] en deux parties et vérifie si la racine se trouve dans la partie gauche ou droite.
    */
   printf("iteration : ");

    if (f(a) * f(b) >= 0) {
        printf("f(a) * f(b) >= 0 alors il n'y a pas de racine dans l'intervalle [a, b]\n");
        return -1;        // erreur.
    }

    double c;

    for (int i = 0; i < max_iter; i++){

        printf(".");

        // point du millieu
        c = (a + b) / 2.0;                    
        if (f(c) == 0 || (b - a) / 2 < tol) {
            printf("\n");
            return c;    
        }
        if (f(c) * f(a) < 0) {
            // la solutin est dans [a, c]
            b = c;                          
        } else {
            // autrement, c'est dans [c, b]
            a = c;         
        }
    }

    printf("\n");                       // pour une meilleure lisibilite de la sortie
    return c;
}

double newton_method(double x0, double tol, int max_iter) {
    /*
        la methode de Newton utilise la derivee de l'equation pour trouver les racines.
    */

    double x = x0;

    printf("iteration : ");
    
    for (int i = 0; i < max_iter; i++) {
        double fx = f(x);
        double fx_diff = f_diff(x);

        printf(".");

        if (fx_diff == 0) {
            printf("La derivee est nulle, la methode de Newton echoue.\n");
            return -1;                   // return error.
        }

        double x_new = x - fx / fx_diff; // formule de Newton

        if (fabs(x_new - x) < tol) {
            printf("\n");
            return x_new;                // solution trouvee
        }
        x = x_new;                       // mise a jour pour la prochaine iteration
    }

    printf("\n");                       // pour une meilleure lisibilite de la sortie

    return x;                            // retourne la meilleure approximation apres max_iter iterations
}

double scecante_method(double x0, double x1, double tol, int max_iter) {
    /*
        la methode de secante est une variante de la methode de Newton qui n'utilise pas la derivee de l'equation.
    */

    double x_prev = x0;
    double x_curr = x1;

    printf("iteration : ");

    for (int i = 0; i < max_iter; i++) {
        double fx_prev = f(x_prev);
        double fx_curr = f(x_curr);
        
        printf(".");

        if (fx_curr == fx_prev) {
            printf("f(x_curr) et f(x_prev) sont egaux, la methode de secante echoue.\n");
            return -1;                   // return error.
        }

        double x_new = x_curr - fx_curr * (x_curr - x_prev) / (fx_curr - fx_prev); // formule de secante

        if (fabs(x_new - x_curr) < tol) {
            printf("\n"); 
            return x_new;               // solution trouvee
        }
        x_prev = x_curr;                // mise a jour pour la prochaine iteration
        x_curr = x_new;
    }

    printf("\n");                       // pour une meilleure lisibilite de la sortie
    return x_curr;                      // retourne la meilleure approximation apres max_iter iterations
}