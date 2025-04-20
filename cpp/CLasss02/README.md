# Class 객체지향의 특징

특징 | 의미 | 키워드/예시
| ---- | ---- | --- |
| **캡슐화 (Encapsulation)** | 데이터와 함수를 하나의 클래스 안에 묶음 | `private` , `public` .. |
| **추상화 (Abstraction)** | 불필요한 정보는 숨기고 핵심 기능만 노출 | `abstract class`, 인터페이스 |
| **상속 (Inheritance)** | 기존 클래스를 확장하여 새로운 클래스를 정의 | `class B : public A` |
| **다형성 (Polymorphism)** | 하나의 인터페이스로 다양한 동작 가능 | `virtual` , 오버라이딩 |

## 캡슐화 (Encapsulation)

> 캡슐화 란 관련있는 변수나 함수를 클래스 안에 하나로 묶는 것

> 데이터 보호(data protection) : 외부로부터 클래스에 정의된 속성과 기능들을 보호

> 데이터 은닉(data hiding) : 내부의 동작을 감추고 외부에는 필요한 부분만 노출

1. 정의

   - 필요한부분만 외부로 노출될 수 있도록 하여 각 객체 고유의 독립성과 책임 영역을 안전하게 지키고자 하는 목적으로 사용

2. 키워드

   | 접근 지정자 | 설명 | 접근 가능 위치
   | ------- | ----- | ------ |
   |`private` | 클래스 내부에서만 접근 가능 | 오직 클래스 내부
   | `protected` | 자식 클래스와 내부에서 접근 가능 | 클래스 , 자식 클래스 |
   | `public` | 어디서든 접근 가능 | 전체 영역
   | **default** | C++에서는 클래스에서는 `private` , `struct` 에서는 `public` | 클래스/struct 선언에 따라 다름

3. ex

   ```cpp
   class MyClass {
        int a; // 디폴트 -> private
   private:
        int b;
   protected:
        int c;
   public:
        int d;
        
        void show() {
            a = 1; // 가능
            b = 2; // 가능
            c = 3; // 가능
            d = 4; // 가능
        }
   };
   ```

   ```cpp
   class SubClass : public MyClass {
        void accessTest() {
            // a = 1; x (private이므로 접근 불가)
            // b = 2; x (private이므로 접근 불가)
            c = 3;    // o (protected → 자식 클래스 접근 가능)
            d = 4;   // o (public)
        }
   };
   ```

   ```cpp
   MyClass obj;
   // obj.a = 1; x
   // obj.b = 2; x
   // obj.c = 3; x
   obj.d = 4;
   ```

## 캡슐화의 관계

- `private` 를 통해 데이터 은닉 -> 외부에서 무분별하게 수정 못하게 보호

- `public` 은 꼭 필요한 인터페이스만 노출

- `protected` 는 자식 클래스의 확장성을 위해 열어둠

- **default** 지정자는 `class`, `struct` 에 따라 다르기 때문에 명시적으로 작성하는 것이 권장됨

|지정자 | 클래스 내부 | 자식 클래스 | 외부
| --- | ----- | ---- | ---- |
`private` | O | X | X |
`protected` | O | O | X |
`public` | O | O | O |


## 추상화 (Abstration)

> 컴퓨터 과학에서 추상화는 복잡한 자료, 모듈, 시스템 등으로부터 핵심적인 개념 또는 기능을 간추려 내는 것

1. 정의

   > 객체 지향 프로그래밍에서 의미하는 추상화는 객체의 공통적인 속성과 기능을 추출하여 정의하는것을 의미

   - 사용자는 내부 구현을 몰라도 됨

   - 필요한 기능만 인터페이스 형태로 제공

   - **사용자는 무엇을 해야 하는지만 알면 되고, 어떻게 동작하는지는 몰라도 된다는 개념**

2. 인터페이스 제공 (함수만 공개하고 구현 감춤)

   - ex: 자동차

   - 차량 내부 엔진 점화, 연료 처리 방법은 몰라도 됨

   - 사용자는 **운전** , **시동 on / off** 만 사용 -> 사용자는 인터페이스만 알면 됨

   ```cpp
   class Car {
   public:
        void drive(); // 사용자가 호출하는 것
        void powerOnOff(); // 사용자가 호출하는 것
   private:
        void injectFuel();
        void igniteEngine();
   };
   ```

   - 사용자에게는 함수만 보여주고, 내부 로직은 숨김

3. 추상 클래스 (**Abstract Class**) 와 순수 가상 함수

   TODO

## 참고

- [블로그 참고 - csj000714([C++] 객체지향 프로그래밍: 추상화, 캡슐화, 상속성, 다형성 ...)](https://csj000714.tistory.com/408)

- [블로그 참고 - 코딩온공식블로그(C++ 추상화 구현과 활용)](https://blog.naver.com/spreatics2/222500538863)

- [TCP스쿨 - 추상 클래스](https://tcpschool.com/cpp/cpp_polymorphism_abstract)

- [위키독스 - 가상 함수](https://wikidocs.net/17144)