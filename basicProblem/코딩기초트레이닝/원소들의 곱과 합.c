#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int multiple_total(int num_list[], size_t num_list_len);
int plus_pow_total(int num_list[], size_t num_list_len);

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    return multiple_total(num_list, num_list_len) < plus_pow_total(num_list, num_list_len);
}

int multiple_total(int num_list[], size_t num_list_len) {
    int res = 1;
    
    for (size_t i = 0; i < num_list_len; ++i)
        res *= num_list[i];
    
    return res;
}

int plus_pow_total(int num_list[], size_t num_list_len) {
    int res = 0;
    
    for (size_t i = 0; i < num_list_len; ++i)
        res += num_list[i];
    
    return res * res;
}