# Class

> C의 구조체에서 확장된 C++의 구조체의 또다른 이름

```
[template-spec]
class [ms-decl-spec] [tag [: base-list ]]
{
   member-list
} [declarators];
[ class ] tag declarators;
```

- **데이터와 함수를 하나로 묶은 사용자 정의 타입**

- **객체지향 프로그래밍(OOP)의 중심**

## OOP(Object Oriented Programming)

> 컴퓨터 프로그램을 명령어의 목록으로 보는 시각에서 벗어나 여러 개의 독립된 단위, 즉 **"객체"** 들의 모임으로 파악하고자 하는 것

- 물체, 물건의 **행동** 과 **상태** 를 실체화 시키는 형태의 프로그래밍

- 객체 지향 프로그래밍의 4가지 특징 -> **추상화** , **상속** , **다형성** , **캡슐화**

## 클래스(Class)


> 우리가 붕어빵을 만들어내기 위해서는 붕어빵을 찍어낼 틀이 필요합니다.

> 여기서 붕어빵을 **찍어낼 틀은 클래스**라고 할 수 있습니다. 붕어빵 틀(클래스)은 하나만 있어도 붕어빵(객체)를 여러개 찍어낼 수 있습니다.

```cpp
class 클래스명 {
   // 멤버 변수(상태)

   // ...

   // 멤버 함수(행동)..
};
```

- Class는 **객체(Object)** 를 만들기 위한 설계도

- 변수(데이터) + 함수(동작)를 한 덩어리로 관리

```cpp
class Person {
public:
    string name; // 맴버 변수s
    int age;

    void introduce() { // 맴버 메서드
        cout << "Hi, I'm " << name << " and I'm " << age << " years old." << endl;
    }
};
```

- 멤버 변수 : Class 내부의 데이터

- 멤버 함수 : Class 내부의 메서드

- 접근 지정자

   - `public` : 어디서든 접근 가능

   - `private` : Class 내부에서만 접근 가능

   - `protected` : Class와 상속받은 Class에서만 접근 가능
      

## 객체(Object)

> 객체는 클래스를 기반으로 만들어진 실체입니다, 클래스는 일종의 틀, 그 틀을 이용해 만든 것이 **객체**

```cpp
Person p;
p.name = "B0X";
p.age = 55;
p.introduce(); // Hi, I'm B0X and I'm 55 years old.
```

- 클래스로 만든 실제 인스턴스

- 메모리에 올라간 존재

## 생성자(Constructor)

> 객체가 생성될 때 자동으로 호출되는 특별한 메서드

1. 매개변수 있는 생성자
   
   ```cpp
   class Person {
   public:
       string name;
       int age;

       // 생성자 (Constructor)
       Person(string n, int a) {
           name = n;
           age = a;
       }

       // ...
   }
   ```

   ```cpp
   int main(void)
   {
       Person p("B0X", 65);

       // ...
   }
   ```

   - `Person` 클래스면 생성자도 `Person()`

   - 반환형 X

   - 자동 호출, 객체 생성 시 자동 실행됨

   <br/>

2. 생성자 오버로딩

   ```cpp
   class Dog
   {
   public:
       string name;
       int age;

       // 생성자 1
       Dog()
       {
           name = "무명";
           age = 0;
       }

       // 생성자 2
       Dog(string n, int a)
       {
           name = n;
           age = a;
       }

       void info()
       {
           cout << name << " : " << age << "살" << endl;
       }
   };
   ```

   ```cpp
   int main(void)
   {
       // ...

       Dog d1;
       Dog d2("코코", 3);

       d1.info(); // 이름 없음 : 0살
       d2.info(); // 코코 : 3살

       // ...
   }
   ```

   - 오버로딩 가능, 여러 개 생성자 정의 가능 (매개변수 다르게)

   <br/>

3. 초기화 리스트

   ```cpp
   class Student {
       string name;
       int grade;

   public:
       Student(string n, int g) : name(n), grade(g) {
           // 초기화 리스트를 사용하면 가독성이 높음
       }

       void print() {
           cout << name << "의 학년은 " << grade << "학년입니다." << endl;
       }
   };
   ```

   ```cpp
   class Book
   {
   public:
       Book()
       {
           cout << "기본 생성자 호출됨!" << endl;
       }
   };
   ```
   <br/>
   
4. 디폴트 생성자(Default Constructor)

   ```cpp
   class Book
   {
   public:
       Book()
       {
           cout << "기본 생성자 호출됨~" << endl;
       }
   };
   ```

   <br/>

## 소멸자(Destructor)

> 객체가 소멸될 때 자동으로 호출되는 메서드

```cpp
class ClassName {
public:
    ~ClassName() { 
        // 소멸 시 할 작업
    }
};
```

- 객체가 메모리에서 해제되기 직전에 마지막으로 실행되는 메서드

- 주로 동적 메모리 해제나 리소스 정리 작업을 할 때 사용

-  `~`(틸드)를 붙이면 소멸자(Destructor)

- 클래스당 하나만 정의 가능

<br/>

1. ex

   ```cpp
   class ClassName {
   public:
       ClassName() {
           cout << "생성자 호출!" << endl;
       }
    
       ~ClassName() { 
           cout << "소멸자 호출!" << endl;
       }
   };
   ```

   ```cpp
   ClassName cn;
   // 생성자 호출!
   // 소멸자 호출!
   ```

   <br/>

2. 소멸자가 호출되는 상황

   - 스코프를 벗어날 때 : 지역 변수 객체가 끝나면 소멸

   - `delete`로 삭제할 때 : 동적 할당 객체를 `delete`하면 소멸

   - 프로그램 종료 시 : 전역 객체나 정적 객체가 종료 시 소멸

   <br/>

3. 동적 할당 ex

   ```cpp
   class MyArray {
   int* arr;

   public:
       MyArray(int size) {
           arr = new int[size]; // 동적 할당
           cout << "배열 할당됨" << endl;
       }

       ~MyArray() {
           delete[] arr; // 해제
           cout << "배열 해제됨" << endl;
       }
   };
   ```

   <br/>

## 참고

- [MS Learn - 클래스 (C++)](https://learn.microsoft.com/ko-kr/cpp/cpp/class-cpp?view=msvc-170)

- [블로그 참조 - hexabrain(Class)](https://blog.hexabrain.net/167)

- [Wikipedia - OOP](https://ko.wikipedia.org/wiki/%EA%B0%9D%EC%B2%B4_%EC%A7%80%ED%96%A5_%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D)

- [codestates - 객체 지향 프로그래밍의 4가지 특징ㅣ추상화, 상속, 다형성, 캡슐화](http://codestates.com/blog/content/%EA%B0%9D%EC%B2%B4-%EC%A7%80%ED%96%A5-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D-%ED%8A%B9%EC%A7%95)

- [블로그 참조 - gdngy(클래스와 객체)](https://gdngy.tistory.com/174)

- [위키 독스 - 클래스(class)와 객체(object)](https://wikidocs.net/16468)

- [위키 독스 - 객체지향 프로그램의 이해](https://wikidocs.net/16469)