#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* code) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int size = strlen(code);
    char* answer = (char*)malloc(sizeof(char) * (size + 1));
    memset(answer, 0, sizeof(char) * (size + 1));
    
    int code_idx = 0, answer_idx = 0, mode = 0;
    
    while (code_idx < size) {
        if (mode) {
            if (code[code_idx] == '1')
                mode  = 0;
            else if (code_idx & 1)
                answer[answer_idx++] = code[code_idx];
        } else {
            if (code[code_idx] == '1')
                mode = 1;
            else if (!(code_idx & 1))
                answer[answer_idx++] = code[code_idx];
        }
        code_idx++;
    }
    
    if (*answer == "") strcpy(answer, "EMPTY");
    
    return answer;
}