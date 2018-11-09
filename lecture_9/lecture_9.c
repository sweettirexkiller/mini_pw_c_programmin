//
// Created by Piotr Jankiewicz on 09/11/2018.
//
#include <stdio.h>

int main(int argc, char *argv[]) {
    union {
        unsigned long stp; // stalo pozycyjne
        float zmp;  // zmienno pozycyjne
    } fix2float, float2fix;
    int i, tmp;
    unsigned long maska = 0x80000000; //0x <-- szestnastkowy 1000000... binarnie

    // zamiana liczby stałopozycyjnej 37 000 000 na postac zmp

    fix2float.stp = 37000000;

    for (i = 32; i && !(fix2float.stp & maska); i--, maska >>= 1); // pusta petla ?
    fix2float.stp ^= maska;
    fix2float.stp = (i >= 24) ? (fix2float.stp >> (i - 24)) : (fix2float.stp << (24 - i));
    fix2float.stp |= (127 + (i - 1)) << 23;

    printf("\n%f\n", fix2float.zmp);

    // zamiana liczby zmienno pozycyjnej zmp 37 000 000. na postac stp

    float2fix.zmp = 37000000.;
    tmp = ((float2fix.stp & 0x7F800000) >> 23) - 127;
    float2fix.stp = (float2fix.stp & 0x007FFFFF) | 0x00800000;
    float2fix.stp = (23 - tmp > 0) ? (float2fix.stp >> (23 - tmp)) : (float2fix.stp << (tmp - 23));

    printf("\n%lu\n", float2fix.stp);

    return 0;
}
