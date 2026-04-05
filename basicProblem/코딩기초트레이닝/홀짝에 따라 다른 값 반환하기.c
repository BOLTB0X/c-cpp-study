#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    
    if (n & 1) {
        for (size_t i = 1; i <= n; i += 2) {
            answer += i;
        }
    } else {
        for (size_t i = 0; i <= n; i += 2) {
            answer += (i * i);
        }
    }
    
    return answer;
}