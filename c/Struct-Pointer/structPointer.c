#include <stdio.h>
#include <string.h>    // strcpy 함수가 선언된 헤더 파일
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

struct Person {
    char name[20];
    int age;
};

struct Dog {
    char name[20];
    char breed[20];
    int age;
};

void printPerson(struct Person *p);

int main(void) {
    struct Person p1;

    strcpy(p1.name, "B0X");
    p1.age = 70;
    struct Person *ptr = &p1;

    printf("name: %s, age: %d\n", ptr->name, ptr->age); // name: B0X, age: 70
    
    strcpy(ptr->name, "BOLT");
    ptr->age = 12;

    printf("name: %s, age: %d\n", ptr->name, ptr->age); // name: BOLT, age: 12

    strcpy((*ptr).name, "B0X");
    (*ptr).age = 71;

    printf("name: %s, age: %d\n", ptr->name, ptr->age); // name: B0X, age: 71


    struct Dog *dog = (struct Dog *)malloc(sizeof(struct Dog));

    strcpy(dog->name, "코코");
    strcpy(dog->breed, "시고르자브종");
    dog->age = 3;

    printf("이름: %s, 종: %s, 나이: %d\n", dog->name, dog->breed, dog->age);

    free(dog);
    return 0;
}

void printPerson(struct Person *p) 
{
    printf("name: %s, age: %d\n", p->name, p->age); // name: B0X, age: 71

}