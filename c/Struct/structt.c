#include "stdio.h"
struct Person {
    char name[20];
    int age;
    float height;
};

typedef struct Men {
    char name[20];
    int age;
} Men;

typedef struct {   // 구조체 이름이 없는 익명 구조체
    char name[20];
    int PinNumber;
} Robot; 

int main(void) {
    struct Person p1 = {"B0X", 32, 177.3};

    printf("이름: %s\n", p1.name);
    printf("나이: %d\n", p1.age);
    printf("키: %.1f\n", p1.height);

    Men m = {"B0X", 40};

    Robot r = {"T-32", 32143};

    return 0;
}