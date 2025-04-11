#include <stdio.h>

void change(int **pp);

int main(void) {
    int a = 508;
    int *p = &a;
    int **pp = &p;
    
    // 값 출력
    printf("값 출력 - 변수 a 값 : %d\n", a);        // 508
    printf("값 출력 - *p 로 a 값 접근 : %d\n", *p); // 508
    printf("값 출력 - **pp 로 a 값 접근 : %d\n", **pp); // 508
    printf("=======================================\n");
    
    // 주소 출력 : 어디를 가리키고 있는지 확인
    printf("주소 출력 - 변수 a 의 주소 : %p\n", &a);  // 0061FF1C
    printf("주소 출력 - 포인터 p 의 값 (a의 주소) : %p\n", p);   // &a 와 같음
    printf("주소 출력 - 이중 포인터 pp 의 값 (p의 주소) : %p\n", pp); // &p 와 같음
    printf("=======================================\n");

    // 각자의 주소 : 다 다름
    printf("각자의 주소 - 포인터 p 의 주소 : %p\n", &p);  // 0061FF18
    printf("각자의 주소 - 이중 포인터 pp 의 주소 : %p\n", &pp); // 0061FF14
    printf("=======================================\n");

    int *p2; // 새로운 포인터 변수 선언
    p2 = p;
    printf("*p2 = p 일 때 *p2: %d\n", *p2);
    printf("=======================================\n");

    printf("변경 전 : %d\n", *p); // 508

    change(pp); // p가 b를 가리키게 변경

    printf("변경 후 : %d\n", *p); // 999

    return 0;
}

// 포인터 변수를 변경하는 함수
void change(int **pp) {
    static int b = 999;
    *pp = &b;
}