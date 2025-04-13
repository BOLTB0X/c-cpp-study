# Struct

>  C언어에서 여러 데이터를 하나로 묶어서 관리할 수 있게 해주는 사용자 정의 자료형

만약 인적 정보를 처리한다면 이름, 나이, 키 등을 저장할 변수가 필요함

```c
char name[20];
int age;
float height;
```
`name` , `age` , `float` 변수에는 한 사람의 정보만 저장할 수 있으므로 여러 명의 정보를 저장하려면

`name1` , `name2` 처럼 변수 이름을 바꿔서 계속 추가해야 하는데 이것은 매우 복잡하고 비효율적

```c
char name1[20];
char name2[20];
// ...
char name100[20];

int age1;
int age2;
// ...
int age100;

float height1[100];
float height2[100];
// ...
float height3[100];
```

**자료를 체계적으로 관리하기 위해 `strcut`라는 문법을 제공**

## 정의

```
struct 이름
{
    자료형 변수명;
    자료형 변수명;
}
```

- `struct` 키워드로 정의

- 관련 정보를 하나의 의미로 묶을 때 주로 사용


```c
struct Person {
    char name[20]; // 구조체 맴버1
    int age;       // 구조체 맴버2
    float height;  // 구조체 맴버3
};
```

- 구조체는 보통 `main` 함수 바깥에 정의

```c
struct Person p1 = {"B0X", 32, 177.3};

printf("이름: %s\n", p1.name);
printf("나이: %d\n", p1.age);
printf("키: %.1f\n", p1.height);
```

- 주로 구조체 키워드 부터 작성하고 사용자가 정의한 이름 순으로 선언해서 사용

- `{}` 으로도 맴버 들을 한번에 초기화 가능

## typedef

```
typedef struct 구조체이름 {
    자료형 멤버이름;
} 구조체별칭;
```

`typedef` 을 이용하면 `struct` 없이 정의해서 사용 가능

```c
typedef struct Men {
    char name[20];
    int age;
} Men;
```

```c
Men m = {"B0X", 40};
```

cf.

`typedef`: *자료형의 별칭을 만드는 기능* 

*구조체뿐만 아니라 모든 자료형의 별칭을 만들 수 있음*

```
typedef 자료형 별칭
typedef 자료형* 별칭
```

## 익명 구조체(anonymous structure)

> typedef로 구조체를 정의하면서 이름을 생략할 수 있습니다.

```
typedef struct {
    자료형 멤버이름;
} 구조체별칭;
```

```c
typedef struct {   // 구조체 이름이 없는 익명 구조체
    char name[20];
    int PinNumber;
} Robot; 
```

```c
Robot r = {"T-32", 32143};
```


## 참고

- [코딩도장 - 구조체 사용하기](https://dojang.io/mod/page/view.php?id=407)

- [코딩도장 - 구조체를 만들고 사용하기](https://dojang.io/mod/page/view.php?id=408)

- [코딩도장 - typedef로 struct 키워드 없이 구조체 선언하기](https://dojang.io/mod/page/view.php?id=409)

- [코딩도장 - 익명 구조체 사용하기](https://dojang.io/mod/page/view.php?id=410)

- [블로그 참조 - 나는 개발자다:티스토리](https://studyc.tistory.com/23)
