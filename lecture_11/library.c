// 
// Created by  Peter Yankievich on 24/11/2018.
//
#include <string.h>
#include <stdio.h>
#include "library.h"


void convert(struct Data *table) {
    int i;
    for (i = 0; i < N; i++) {
        num2bin(table[i].value, table[i].bin);
        num2hex(table[i].value, table[i].hex);
        num2dec(table[i].value, table[i].dec);
    }
    return;
}

void num2bin(int value, char buf[M]) {
    char tmp[3 * M];
    int i = 0, j;
    while (0 != value) {
        /*
         * mnozymy i dzielimy przez 2 i odejmujemy - jest to reszta z dzielenia przez 2
         */
        tmp[i] = (char) ('0' + (value - ((value >> 1) << 1)));
        value >>= 1; // gubimy te cyfre ktorej wartosc bin juz znalezmismy
        i++;
    }// po zakończeniu pętli mamy binarna reprezentacje ale w odwrotnej kolejnosci

    if (!i) { // i == 0, tzn powyzsza petla sie nie wykobna i nasze value to '0'
        tmp[i] = '0';
        i++;
    };
    for (j = 0, i--; 0 <= i; j++, i--) { // odwracamy koljenosc
        buf[j] = tmp[i];
    }
    buf[j] = 0;
    return;
}


void num2hex(int value, char buf[M]) {
    char tmp[M];
    int i = 0, j;
    while (value) {
        j = value - ((value >> 4) << 4);
        tmp[i] = (char) ((10 > j) ? ('0' + j) : ('A' + (j - 10)));
        value >>= 4;
        i++;
    }
    if (!i) { // i == 0, tzn powyzsza petla sie nie wykona i nasze value to '0'
        tmp[i] = '0';
        i++;
    };
    for (j = 0, i--; 0 <= i; j++, i--) { // odwracamy koljenosc
        buf[j] = tmp[i];
    }
    buf[j] = 0;

}

void num2dec(int value, char buf[M]) {
    char tmp[M];
    int i = 0, j;
    while (value) {
        tmp[i] = (char) ('0' + value % 10);
        value /= 10;
        i++;
    }
    if (!i) { // i == 0, tzn powyzsza petla sie nie wykobna i nasze value to '0'
        tmp[i] = '0';
        i++;
    };
    for (j = 0, i--; 0 <= i; j++, i--) { // odwracamy koljenosc
        buf[j] = tmp[i];
    }
    buf[j] = 0;

}

void sort(struct Data table[N], enum systemBase sB) {
    int i, j, swap;
    char buf[sizeof(struct Data)];

    for (i = N - 1; 0 < i; i--) {

        for (j = 0; j < i; j++) {

            switch (sB) {
                case bin:
                    swap = strcmp(table[j].bin, table[j + 1].bin);
                    break;
                case hex:
                    swap = strcmp(table[j].hex, table[j + 1].hex);
                    break;
                case dec:
                    swap = strcmp(table[j].dec, table[j + 1].dec);
                    break;
            }

            printf("%s", (void *)buf);
            if (!swap) {
                //przepisuje j element tablicy do buf
                memcpy(
                        (void *) buf,
                        (void *) &table[j],
                        sizeof(table[j])
                );
                //przepisuje j element tablicy do j+1
                memcpy(
                        (void *) &table[j],
                        (void *) &table[j + 1],
                        sizeof(table[j + 1])
                );
                //przepusujemy buf do j+1
                memcpy(
                        (void *) &table[j + 1],
                        (void *) buf,
                        sizeof(table[j + 1])
                );
            }

        }
    }
    return;
}


