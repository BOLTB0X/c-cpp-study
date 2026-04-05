#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int circle_operation(int a, int b);
int particular_operation(int a, int b);

int solution(int a, int b) {
    int res1 = circle_operation(a, b);
    int res2 = particular_operation(a, b);
    return res1 >= res2 ? res1 : res2;
}

int circle_operation(int a, int b) {
    char _a[6], _b[6];
    sprintf(_a, "%d", a);
    sprintf(_b, "%d", b);
    
    return atoi(strcat(_a, _b));
}

int particular_operation(int a, int b) {
    return 2 * a * b;
}
