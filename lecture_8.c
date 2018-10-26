#include <stdio.h>
#include <math.h>

#define N 5 // rozmiar macierzy

void MacierzJednostkowa(float A[N][N]);

void MacierzZerowa(float A[N][N]);

void dodajMacierze(float A[N][N], float B[N][N]);

double NastepnySladnik(int m, float Nast[N][N], float Pop[N][N], float A[N][N]);

//void WypiszMacierz(float Ma[N][N]);

void expA(void);

int main() {
//    expA();
    printf("xd forever\n");
    return 0;
}

void MacierzZerowa(float A[N][N]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; i++)
            A[i][j] = 0;
    return;
}

void MacierzJednostkowa(float A[N][N]) {
    MacierzZerowa(A);
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; i++)
            if (i == j) A[i][j] = 1;
    return;
}

double NasteonySkladnik(int m, float Nast[N][N], float Pop[N][N], float A[N][N]) {
    int i, j, k;
    float suma, norma;
    norma = 0.0;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            suma = 0.0;
            for (k = 0; k < N; k++)
                suma += Pop[i][k] * A[k, j];
            suma /= m;
        }
    return norma;
}


void expA(void) {
    short int m;
    float eps, norma;
    float A[N][N], sklNp[N][N], sklPr[N][N], Wynik[N][N];

    MacierzJednostkowa(A);
    MacierzJednostkowa(sklPr);
    MacierzJednostkowa(Wynik);

    eps = 0.01;
    m = 1;

    do {
        if (0x0001 & m) {
            norma = NastepnySladnik(m, sklNp, sklPr);
            dodajMacierze(Wynik, sklPr);
        }
        m += 1;

    } while (norma >= eps);
}

void dodajMacierze(float A[N][N], float B[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <; ++j) {
            A[i][j] += B[i][j];
        }
    }
    return;
}

