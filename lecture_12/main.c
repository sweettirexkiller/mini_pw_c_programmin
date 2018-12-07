#include <stdio.h>
#include <math.h>

#include "library.h"


int main() {
    double x0, eps = 0.00001;

    x0 = functionRoot(0.0, 2.0, eps, funF_G);

    x0 = integral(0.0, x0, eps, funF)
         - integral(0.0, x0, eps, funG)
         + integral(x0, 2.0, eps, funG)
         - integral(x0, 1.0, eps, funF);

    printf("integral =%8.4f\n", 4.*x0); //szerokosc_pola.liczba_miejsc_po_kropce
    return 0;
}