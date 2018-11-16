//
// Created by Piotr Jankiewicz on 16/11/2018.
//
#include "stdio.h"

int main(int argc, char* argv[])
{
    int *pTemp, x,y,tab[10];

    pTemp = &x; // dereference
    printf("%d", *pTemp);
}