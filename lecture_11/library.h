// 
// Created by  Peter Yankievich on 24/11/2018.
//

#ifndef CONVERTER_LIBRARY_H
#define CONVERTER_LIBRARY_H

#define M 11
#define N 100

enum systemBase {
    bin, dec, hex
};

struct Data { // TYPE: structure
    int value;
    char hex[M];
    char dec[M];
    char bin[3 * M];
};


void convert(struct Data table[N]);

void sort(struct Data table[N], enum systemBase sB);

void num2bin(int value, char buf[3 * M]);

void num2hex(int value, char buf[M]);

void num2dec(int value, char buf[M]);

#endif //CONVERTER_LIBRARY_H
