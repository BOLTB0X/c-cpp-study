# Struct Pointer

- 구조체도 결국 하나의 데이터 덩어리(메모리)

   ```c
   struct Person
   {
       char name[20];
       int age;
   };
   ```

- 구조체를 포인터로 가리킨다면 -> 구조체 포인터

   ```c
   strcpy(p1.name, "B0X");
   p1.age = 70;

   struct Person *ptr = &p1;
   ```

   - `ptr` 은 `p1` 의 주소를 가리킴
   


## 멤버 접근

- 기존방식

   ```c
   strcpy((*ptr).name, "B0X");
   (*ptr).age = 71;
   ```
   
- `->`

   ```c
   strcpy(ptr->name, "BOLT");
   ptr->age = 12;

   printf("name: %s, age: %d\n", ptr->name, ptr->age); // name: BOLT, age: 12
   ```

cf. *구조체 포인터를 함수 인자로 쓴다면?*

```c
void printPerson(struct Person *p) 
{
    printf("name: %s, age: %d\n", p->name, p->age);

}
```

- 구조체는 크기가 클 수 있으므로
함수를 호출할 때 포인터로 전달하면 **메모리 효율이 좋음**


## 동적할당

> 구조체는 멤버 변수가 여러 개 들어있어서 크기가 큰 편입니다. 그래서 구조체 변수를 일일이 선언해서 사용하는 것보다는 포인터에 메모리를 할당해서 사용하는 편이 효율적입니다.

```
struct 구조체이름 *포인터이름 = malloc(sizeof(struct 구조체이름));
```

구조체 포인터에 메모리를 할당하는 방식 -> (`malloc`) 주로 사용

```c
struct Dog {
    char name[20];
    char breed[20];
    int age;
};
```

```c
struct Dog *dog = (struct Dog *)malloc(sizeof(struct Dog));

strcpy(dog->name, "코코");
strcpy(dog->breed, "시고르자브종");
dog->age = 3;

printf("이름: %s, 종: %s, 나이: %d\n", dog->name, dog->breed, dog->age);

free(dog);
```

## 참고

- [코딩도장 - 구조체 포인터를 선언하고 메모리 할당하기](https://dojang.io/mod/page/view.php?id=418)