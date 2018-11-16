#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "time.h"

void unityMatrix(int, double *);

void addMatricies(int, double *, double *);

double nextComponent(int, int, double *, double *, double *);

void printArray(int, double *);

void expA(int, double, double *, double *, double *, double *);

int main(int argc, char *argv[]) {

    // Eps- dokladnosc,
    // A* - dlugi wektor czyli a do potegi,
    // wynik  -  exponenta,
    // sklNp - skladnik nieparzusty,
    // sklPr  - skladnik parzysty;
    double *A, *Wynik, *SklNp, *SklPr;
    double eps;

    int N, i, j;
    scanf("%d", &N);
    A = (double *) malloc(N * N * sizeof(double));

    Wynik = (double *) malloc(N * N * sizeof(double));
    SklNp = (double *) malloc(N * N * sizeof(double));
    SklPr = (double *) malloc(N * N * sizeof(double));

    srand((unsigned) time(NULL));

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            *(A + i * N + j) = rand() % 10;
        }
    }

    printArray(N,A);

    eps = 0.0001;
    expA(N, eps, A, Wynik, SklNp, SklPr);
    printArray(N, Wynik);


    free(SklPr);
    free(SklNp);
    free(Wynik);
    free(A);


    return 0;
}

void unityMatrix(int N, double A[]) {
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (i == j) {
                A[i * N + j] = 1.0;
            } else {
                A[i * N + j] = 0.0;
            }
        }
    }
    return;
}

void printArray(int N, double A[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.1f ", A[i * N + j]);
        }
        printf("\n");
    }
    return;
}

void addMatricies(int N, double A[], double B[]) {
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            A[i * N + j] += B[i * N + j];
        }
    }
    return;
}

double nextComponent(int N, int m, double *Next, double *Prev, double *A) {
    double sum, norm;
    norm = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum = 0.0;
            for (int k = 0; k < N; ++k)
                sum += Prev[i * N + k] * A[k * N + i];

            sum /= m;
            Next[i * N + j] = sum;
            if (norm < fabs(sum)) norm = sum;
        }
    }

    return norm;
}

void expA(int N, double eps, double *A, double *Wynik, double *Next, double *Prev) {
    short int m;
    double norm;
    unityMatrix(N, Prev);
    unityMatrix(N, Next);
    m = 1;

    do {
        if (0x0001 & m){
            norm = nextComponent(N,m,Next, Prev, A);
            addMatricies(N,Wynik,Next);
        } else {
            norm = nextComponent(N,m,Prev, Next, A);
            addMatricies(N,Wynik,Prev);
        }
        m +=1;
    } while (norm >= eps);
    return;
}