// 
// Created by  Peter Yankievich on 02/12/2018.
//

#include "library.h"
#include <math.h>

double funF(double x) {
    return 3.0 * sqrt(1 - x * x);
}

double funG(double x) {
    return sqrt(1 - x * x / 4.);
}

double funF_G(double x) {
    return funF(x) - funG(x);
}

double functionRoot(double a, double b, double eps, double fun(double x)) {
    double tmp;
    do {
        tmp = fun((a + b) / 2.0); //  value of the function in the middle of a given range
        if (fabs(tmp) < eps / 10.) break; // if function is close enough to the root(zero)
        else if (tmp * fun(a) < 0) b = (b + a) / 2; // if tmp and fun(a) have different sign + or -, change the range
        else a = (b + a) / 2.0;
    } while (b - a >= eps);
    return (a + b) / 2.0;
}

double integral(double a, double b, double eps, double fun(double x)) {
    int i, nPodzial;
    double x, podPrz, nastWart, popWart;
    popWart = (b - a) + fun(a); // pole prostokata
    nastWart = (b - a) / 2. + (fun(a) + fun((a + b) / 2.0)); //  dzielimy na dwa i nastapne dwa prostokaty
    nPodzial = 2; // mamy dwa przedzialy
    while (fabs(popWart - nastWart) >= eps) { // dopoki dwa kolejne przyblizenia sa odlegle o wiecej niz epsilon
        popWart = nastWart; // nast staje sie poprzednia
        nPodzial *= 2;
        podPrz = (b - a) / nPodzial; //  dlugosc podprzydzialu
        x = a; // zaczynamyt obliczanie wyskosci od punktu a
        nastWart = 0;
        for (i = 0; i < nPodzial; i++) {
            nastWart = nastWart + fun(x); // dodajemy wysokosci kolejnych prostokatow
            x += podPrz;
        }
        nastWart *= podPrz;
    }
    return nastWart;
}



//ALTERNATIVE
//
// void funF(double *pWynik, double x){
//    double wartosc;
//    wartosc = 3.*sqrt(1-x*x); // *pWynik = sqrt(1-x*x);
//    *pWynik = wartosc; // do pola o adresie pWynik przypisz wartosc
//    return;
//}

