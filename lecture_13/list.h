// 
// Created by  Peter Yankievich on 07/12/2018.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H



typedef struct listElement {
    int data;
    struct listElement *next; // cycle structure (reference to its kind)
} listElement;

listElement *createList(int);
void sieve(listElement*);
void print(listElement*);
void clean(listElement*);


#endif //LIST_LIST_H
