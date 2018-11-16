#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "time.h"

void unityMatrix(int, double *);

void addMatricies(int, double *, double *);

double nextComponent(int, int, double *, double *, double *);

void expA(int, double *, double *, double *, double *);

int main(int argc, char *argv[]) {

    //eps- dokladnosc,
    // A* - dlugi wektor czyli a do potegi,
    // wynik to exponenta, sklNp skladnik nieparzusty, sklPr skladnik parzysty;
    double eps, *A, *Wynik, *SklNp, *sklPr;

    int N, i, j;
    scanf("%d", &N);
    A = (double *) malloc(N * N * sizeof(double));

    Wynik = (double *) malloc(N * N * sizeof(double));
    SklNp = (double *) malloc(N * N * sizeof(double));
    sklPr = (double *) malloc(N * N * sizeof(double));

    srand((unsigned) time(NULL));

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            *(A + i * N + j) = rand() % 10;
        }
    }


    free(sklPr);
    free(SklNp);
    free(Wynik);
    free(A);
    return 0;
}