#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int circle_plus(const char *a, const char *b);

int solution(int a, int b) {
    int answer = 0;
    char *str_a = malloc(sizeof(char) * 6), *str_b = malloc(sizeof(char) * 6);
    sprintf(str_a, "%d", a);
    sprintf(str_b, "%d", b);
    
    int ab = circle_plus(str_a, str_b);
    int ba = circle_plus(str_b, str_a);
    
    if (ab >= ba)
        answer = ab;
    else
        answer = ba;
        
    free(str_a);
    free(str_b);
    return answer;
}

int circle_plus(const char *a, const char *b) {
    char _a[6], _b[6];
    strcpy(_a, a);
    strcpy(_b, b);
    return atoi(strcat(_a, _b));
}
