// 
// Created by  Peter Yankievich on 14/12/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int op = 0;

int fibRec(int n) {
    if (n <= 1) return n;
    else return fibRec(n - 1) + fibRec(n - 2);
}

int fib(int n) {
    int i, current, prevPrev = 0, prev = 1;
    if (n <= 1) return n;
    for (i = 2; i <= n; i++) {
        current = prevPrev + prev;
        prevPrev = prev;
        prev = current;
    }
    return current;
}

//wieża hanoi
void bezposrednio(char z, char na) {
    printf("Przeniesienie bezposrednio z %2c na %2c\n", z, na);
    return;
}

void przenies(char z, char na, char pom, int ile) {
    if (ile == 1) {
        bezposrednio(z, na);
    } else {
        przenies(z, pom, na, ile - 1);
        bezposrednio(z, na);
        przenies(pom, na, z, ile - 1);
    }
    return;
}

int main(void) {
//    clock_t begin = clock();
    int n = 4;
    przenies('A', 'C', 'B', n);

//    clock_t end = clock();
//    double time_spent = (double) (end - begin) / CLOCKS_PER_SEC;
//    printf("%d\n", fib(10));
//    printf("%d\n", fibRec(10));
//    printf("Time for blocks %d in Hanoi Tower is %.2f\n sec. Number of operations: %ld\n", n, time_spent, op);
    return 0;
}