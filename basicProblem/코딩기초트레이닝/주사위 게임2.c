#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int a, int b, int c) {
    if (a == b && b == c)
        return (a + b + c) * (int)(pow(a, 2) + pow(b, 2) + pow(c, 2)) * (int)(pow(a, 3) + pow(b, 3) + pow(c, 3));
    else if ((a == b && b != c) || 
              (b == c && a != c) ||
              (a == c && b != c))
        return (a + b + c) * (int)(pow(a, 2) + pow(b, 2) + pow(c, 2));
    return a + b + c;
}