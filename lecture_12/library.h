// 
// Created by  Peter Yankievich on 02/12/2018.
//

#ifndef INTEGRAL_LIBRARY_H
#define INTEGRAL_LIBRARY_H

double funF(double x);
double funG(double x);
double funF_G(double x);

double functionRoot(double a, double b, double eps, double fun(double x)); // only pointer to function is passed

double integral(double a, double b, double eps, double fun(double x)); // intergral of the function in a given range

#endif //INTEGRAL_LIBRARY_H
