// 
// Created by  Peter Yankievich on 07/12/2018.
//
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

listElement *createList(int elemNum){
    int i;
    listElement *new,  *beg = NULL;
    for(i = elemNum; i > 0; i--){
        new = (listElement*)malloc(sizeof(listElement));
        new->data = i;
        new->next = beg;
        beg = new;
    }
    return beg;
}

void sieve(listElement* beg){
    listElement *p = beg, *q, *r;
    int i;
    while(p){
        i = p->data;
        q = p;
        r = q->next;
        while(r){
            if((r->data%i)){
                //deleting list element
                q->next = r->next;
                free(r);
                r = q->next;
            } else {
                q = r;
                r = q->next;
            }
        }
        p = p->next;
    }
    return;
}

void print(listElement *beg){
    int i = 1;
    if(beg == NULL) return;
    printf("Index      Liczba\n");
    while(beg){
        printf("%13d%17d\n", i, beg->data);
        i++;
        beg = beg->next; // in this function we loose head
    }
    return;
}
void clean(listElement* beg){
    listElement *tmp;
    while(beg != NULL){
        tmp = beg;
        beg = beg->next;
        free(tmp);
    }
    return;
}