#include <stdio.h>

int main(void)
{
    int a = 10;
    int *p = &a;        // a의 주소를 저장하는 포인터 p 선언
    printf("%p\n", &a); // 변수 a의 메모리 주소
    printf("%d\n", *p); // 포인터 p가 가리키는 위치의 값 10

    *p = 20;                   // 포인터 p가 가리키는 주소에 20 저장
    printf("%d\n", a);         // a 값 20 변경
    printf("%p\n", (void *)p); // 변수 a의 메모리 주소
    return 0;
}