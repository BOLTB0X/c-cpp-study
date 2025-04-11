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
    
    int n1 = 10;
    int n2 = 20;

    *p = n1;
    int *q = &n2;

    // printf("n1 초기 값 %d , n2 초기 값 %d\n", n1, n2);
    // printf("===============================\n");

    // p = q;

    // printf("*p  값 %d , *q  값 %d\n", *p, *q);
    // printf("원본 n1  값 %d , 원본 n2  값 %d\n", n1, n2);
    // printf("===============================\n");

    // *p = 999;

    // printf("원본 n1  값 %d , 원본 n2  값 %d\n", n1, n2);
    // printf("===============================\n");


    *p = *q;
    printf("*p : %d , *q : %d\n", *p, *q);
    printf("n1 : %d, n2 : %d\n", n1, n2);
    printf("p : %p, q : %p\n", (void *)p, (void *)q); // 주소는 다름
    printf("===============================\n");

    p = q;
    printf("*p : %d , *q : %d\n", *p, *q);
    printf("n1 : %d, n2 : %d\n", n1, n2);
    printf("p : %p, q : %p\n", (void *)p, (void *)q); // 주소는 같음
    printf("===============================\n");
    return 0;
}