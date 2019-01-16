// 
// Created by  Peter Yankievich on 16/01/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getBit(unsigned n, int i);

int main() {
    unsigned char needle = 0xFF; // 1 byte 255 11111111
    unsigned int haystack = 0x0; // 4 bytes


    haystack |= (0xFF) << 24; // first 8 bits zeros , then 8 bits ones

    int j;
    for(j = 31; j; j--){
        printf("%d ", (haystack & (0x1 << j)) ? 1 : 0);
    }
    printf("\n");
    printf("\n");

    unsigned char mask = ~0x0;

    for(j = 1; j; j--){
        printf("%d ", (mask & (0x1 << j)) ? 1 : 0);
    }
    printf("\n");
    printf("\n");

    unsigned int i;
    for(i = (0x1<<23); i; i>>=1){
        unsigned int tmpIdx = i;
        unsigned int tmpHaystack = haystack;
        unsigned char mask = ~0x0;
        while(tmpIdx >>=1){
            tmpHaystack >>=1;
        }
        tmpHaystack &= mask;
        int j;
        for(j = 31; j > 0; j--){
            printf("%d ", (tmpHaystack & (0x1 << j)) ? 1 : 0);
        }
        printf("\n");

    }



    return 0;
}

