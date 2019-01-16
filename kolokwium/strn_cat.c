// 
// Created by  Peter Yankievich on 16/01/2019.
//

#include <stdio.h>
#include <stdlib.h>

char *my_strcat(char *d, const char *s, int n);

int main() {

    char *d, *s;
    d = malloc(5);
    s = malloc(5);
    d = "abcd\0";
    s = "efgh\0";

    d = my_strcat(d, s,3);
    printf("%s\n", d);

    return 0;
}

char *my_strcat(char *d, const char *s, int n) {
    int dLen = 0, sLen = 0, i, j;
    while (d[dLen++] != '\0');
    while (s[sLen++] != '\0');

    for(i = dLen, j = 0; i < dLen + n; i++, j++){
        d[i] = s[j];
    }

    d[dLen + n] = '\0';

    return d;
}
