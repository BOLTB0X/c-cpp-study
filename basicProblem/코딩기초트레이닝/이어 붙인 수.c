#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int attach_odd(int *num_list, size_t num_list_len);
int attach_even(int *num_list, size_t num_list_len);

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    return attach_odd(num_list, num_list_len) + attach_even(num_list, num_list_len);
}

int attach_odd(int *num_list, size_t num_list_len) {
    int res = 0, p = 1;
    
    for (int i = num_list_len - 1; i >= 0; --i) {
        if (num_list[i] & 1) {
            res += num_list[i] * p;
            p *= 10;
        }
    }
    
    return res;
}

int attach_even(int *num_list, size_t num_list_len) {
    int res = 0, p = 1;
    
    for (int i = num_list_len - 1; i >= 0; --i) {
        if (num_list[i] % 2 == 0) {
            res += num_list[i] * p;
            p *= 10;
        }
    }
    
    return res;
}