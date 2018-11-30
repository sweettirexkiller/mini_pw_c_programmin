// 
// Created by  Peter Yankievich on 23/11/2018.
//
#include "stdio.h"
#include "string.h"
#include "library.h"

int main(int argc, char *argv[]) {
    int i;
    struct Data table[N];
    for (i = 0; i < N; ++i) {
        table[i].value = i; // 0 1 2 3 ..... 97 98 99
    }


    convert(table);
    sort(table, bin);

    for(i = 0; i < N; i++){
        printf("%s ", table[i].bin);
    }

//    sort(table, dec);
//    sort(table, hex);


    return 0;
}





