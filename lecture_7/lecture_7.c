//
// Created by Piotr Jankiewicz on 26/10/2018.
//

// Eratosthenes Algorithm for fining primal numbers

#include "stdio.h"

#define N 1000

int main() {
    int i, j;
    int table[N];
    for (i = 2; i < N; i++) {
        table[i] = i;
    }

    for (i = 2; i < N; i++) {
        if (table[i] > 0) {
            j = table[i] * 2;
            while (j < N) {
                table[j] = 0;
                j = j + table[i];
            }

        }
    }

    printf("Primal numbers: \n");
    for (i = 2; i < N; i++) {
        if (tablica[i] > 0) {
            printf("%5d", table[i]);
        }
    }

    return 0;
}