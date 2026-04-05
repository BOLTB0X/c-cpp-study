#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* str1, const char* str2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int size = strlen(str1) + strlen(str2) + 1;
    char* answer = (char*)malloc(sizeof(char) * size);
    
    memset(answer, 0, sizeof(char) * size);
        
    for (size_t i = 0; i < strlen(str1); ++i) {
        answer[i * 2] = str1[i];
        answer[i * 2 + 1] = str2[i];
    }
    
    return answer;
}