#include <stdio.h>
#include <math.h>

#define N 5 // quadratic matrix size

void unitMatrix(float A[N][N]);

void zeroMatrix(float A[N][N]);

void addMatricies(float A[N][N], float B[N][N]);

double nextComponent(int m, float Next[N][N], float Last[N][N], float A[N][N]);

//void printMartix(float Ma[N][N]);

void expA(void);

int main() {
    expA();
    return 0;
}

void zeroMatrix(float A[N][N]) {
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            A[i][j] = 0;
    return;
}

void unitMatrix(float A[N][N]) {
    zeroMatrix(A);
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            if (i == j) A[i][j] = 1;
    return;
}

double nextComponent(int m, float Next[N][N], float Last[N][N], float A[N][N]) {
    int i, j, k;
    float sum, norm;
    norm = 0.0;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            sum = 0.0;
            for (k = 0; k < N; k++)
                sum += Last[i][k] * A[k][j];
                sum /= m;
        }
    return norm;
}


void expA(void) {
    short int m;
    float epsilon, norm = 0;
    float mainMatrix[N][N], nextPart[N][N], lastPart[N][N], Result[N][N];

    unitMatrix(mainMatrix);
    unitMatrix(nextPart);
    unitMatrix(lastPart);

    epsilon = 0.01;
    m = 1;

    do {
        if (0x0001 & m) { // <-- this is binary logical expression for conjunction (even check)
            norm = (float) nextComponent(m, nextPart, lastPart, mainMatrix);
            addMatricies(Result, lastPart);
        }
        m += 1;

    } while (norm >= epsilon);
}

void addMatricies(float A[N][N], float B[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <N; ++j) {
            A[i][j] += B[i][j];
        }
    }
    return;
}

