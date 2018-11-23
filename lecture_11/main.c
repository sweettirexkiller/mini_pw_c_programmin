// 
// Created by  Peter Yankievich on 23/11/2018.
//

#include "stdio.h"
#include "string.h"

#define M 16;

int main(int argc, char *argv[]) {
    //char tab[N]; // string
    /*
     * String library functions:
     *
     * - size_t strlen(const char *s) //  STRING LENGTH -- site_t is unsigned integer
     *
     * - int strcmp(const char * s1, const char * s2) // COMPARE
     *
     * - char * strcpy(const char* dest, const char *src) // COPY
     *
     * - char * strcat(char * dest, const char * src) // CONCATENATION
     *
     * - void * memset(void *s, int c, size_t n) // MEMORY SET
     *
     * - void * memcpy(void * dest, const void * source, size_t n) // MEMORY COPY
     *
     */

    struct Data { // TYPE: structure
        int value;
        char hex[M];
        char dec[M];
        char bin[3 * M];
    };

    enum systemBase {bin, dec,hex}; //TYPE: enumerate



    return 0;
}
