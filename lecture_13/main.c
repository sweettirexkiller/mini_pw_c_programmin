//
// Created by  Peter Yankievich on 07/12/2018.
//
#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int main(){
    listElement *beg;
    int n;
    scanf("give me first element: %d", &n);

    beg = createList(n);
    print(beg);

    sieve(beg);
    print(beg);

    clean(beg);

    return 0;
}