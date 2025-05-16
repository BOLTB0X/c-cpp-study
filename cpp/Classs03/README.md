# Contents

- [Abstract Class](https://github.com/BOLTB0X/c-cpp-study/tree/main/cpp/Classs03#abstract-class)

- [Inheritance](https://github.com/BOLTB0X/c-cpp-study/tree/main/cpp/Classs03#inheritance)

- [Method Overloading & Method Overriding](https://github.com/BOLTB0X/c-cpp-study/tree/main/cpp/Classs03#method-overloading%EA%B3%BC-method-overriding)

# Abstract Class

> 추상 클래스란 하나 이상의 **순수 가상 함수(Pure Virtual Function)** 를 포함한 클래스

- 직접 객체를 생성할 수 없고, **이를 상속받은 자식 클래스가 구현해야하는 Class**

- 순수 가상 함수를 하나 이상 포함하는 클래스

## 순수 가상 함수(Pure Virtual Function) 

```cpp
virtual 반환형 함수이름(매개변수) = 0;
```

- 함수 선언 뒤에 `= 0` 을 붙여서 선언하는 함수

- 이렇게 선언된 **순수 가상 함수** 가 있다면, 이를 **추상클래스(abstract class)** 라 함

## 생성 불가 Case

### 추상클래스만 생성한 경우

```cpp
// 추상 클래스: Animal
class Animal {
public:
    virtual void sound() = 0; // 2
};
```
```cpp
int main() {
    Animal a; // 3

    return 0;
}
```

1. 추상 클래스 -> `Animal`

2. 순수 가상 함수

3. 추상 클래스이므로 **객체 생성 불가**

### 함수 재정의

```cpp
class Animal {
public:
    virtual void sound() = 0;

    void breathe() {
        cout << "동물이 숨을 쉽니다.\n";
    }
};
```

- `breathe` 함수를 정의해주고 맴버변수를 선언 

- 순수 가상 함수(pure virtual function)이 존재하기 때문에


- 객체 선언 X

## 파생 클래스

> 상속 받은 클래스를 선언해야 함

```cpp
class Dog : public Animal { // 1
public:
    void sound() override { // 2
        cout << "멍멍!\n";
    }
};
```

1. **추상 클래스** 는 객체 생성 불가하므로 상속을 통해 사용해야 함

2. 파생 클래스에서 반드시 순수가상함수를 `override` 해야 함

```cpp
int main() {

    Dog d;

    d.sound();
}
```

```
멍멍!
동물이 숨을 쉽니다.
```
## 언제 추상 클래스와 순수 가상 함수가 필요한가?

- **인터페이스(통일된 명세)** 를 제공하여, 상속받는 클래스들이 공통 기능을 반드시 구현하게 하기 위해

   - 동물의 울음 소리가 다 다름
   - `sound()` 각각 구현해야할 경우

   ---

- **다형성(polymorphism)** 을 활용하여, 하나의 포인터(또는 참조)를 통해 다양한 객체를 조작하기 위해

   - 버튼 클릭, 파일 저장 등 이벤트 처리 시스템

   ---

- 공통 동작은 부모 클래스에서, 개별 동작은 자식 클래스에서 강제 구현하고 싶을 때

   - 객체를 배열이나 리스트에 저장해 같은 방식으로 처리

## 추상클래스가 필요한 경우 (ex. 게임 파티)

```cpp
// 추상 클래스
class Character {
public:
    virtual void attack() = 0; // 순수 가상 함수
    virtual void move() = 0;

    virtual ~Character() {} // 소멸자도 virtual로
};
```

1. **전사 클래스**

   ```cpp
   class Warrior : public Character {
    public:
        void attack() override {
            cout << "검으로 공격!\n";
        }
        void move() override {
            cout << "걸어서 이동!\n";
        }
   };
   ```

   ---

2. **마법사 클래스**

   ```cpp
   class Mage : public Character {
    public:
        void attack() override {
            cout << "마법을 사용!\n";
        }
        void move() override {
            cout << "순간이동!\n";
        }
   };
   ```

   ---

3. 사용

   ```cpp
   vector<Character*> party;

   party.push_back(new Warrior());
   party.push_back(new Mage());

   for (auto c : party) {
       c->attack();
       c->move();
   }

   // 메모리 정리
   for (auto c : party) {
       delete c;
   }
   ```

# Inheritance

> 기존에 존재하는 클래스를 바탕으로 새로운 클래스를 확장하는 개념

**부모 클래스(기반 클래스, Base Class)** 의 **속성과 기능을 자식 클래스(파생 클래스, Derived Class)** 가 물려 받는 것

## 기본 사용법

>  `:` 기호와 함께 상속 방식과 상속받을 클래스의 이름을 넣어주면 됌

```cpp
class 부모클래스 {
    // 1
};

class 자식클래스 : [접근지정자] 부모클래스 { // 2
    // 3
};
```

1. 멤버 변수, 멤버 함수

2. 접근지정자 `public` , `private` , `protected`

3. 새로운 멤버 변수, 함수 추가 가능

## 특징

- 자식 클래스는 부모의 멤버 변수/함수를 사용할 수 있음

- 자식 클래스는 추가적인 기능을 더하거나, 부모의 메서드를 오버라이드(재정의) 가능

- 부모 클래스 생성자 -> 자식 생성자 순서로 호출됨

- 자식 클래스 소멸자 -> 부모 소멸자 순서로 호출됨

---

| 부모의 멤버 접근 지정자  | `public` 상속 | `protected` 상속 | `private` 상속 |
| -------------- | ----------- | -------------- | ------------ |
| `public` 멤버    | `public`    | `protected`    | `private`    |
| `protected` 멤버 | `protected` | `protected`    | `private`    |
| `private` 멤버   | **상속 X**   | **상속 X**      | **상속 X**    |


---

## `public` 상속 (가장 일반적인 case)

- 부모의 `public` -> 자식도 `public`

- 부모의 `protected` -> 자식도 `protected`

- 외부에서도 부모의 `public` 멤버에 접근 가능

```cpp
class Animal {
private:
    void substance(void) {
        cout << "유기체" << '\n';
    }
public:
    void eat(void) {
        cout << "먹는다!" << '\n';
    }
};

class Dog : public Animal { // // Animal을 상속받은 Dog 클래스
public:
    void bark(void) {
        cout << "멍멍!" << '\n';
    }
    
    void question(void) {
        cout << jong << '\n';
    }
};
```

```cpp
d.eat();   // 1
d.bark();  // 2
// d.substance() // 3

// cout << d.jong << '\n'; 4
d.question(); // 5
```

1. 부모 클래스의 `public` 맴버 함수 사용 가능

2. 자식 클래스 고유 함수

3. `private` 맴버 함수 사용 불가

4. 외부에서 부모 클래스의 `protected` 접근 불가

5. `question` 로 접근해서 사용해야함

---

## `protected` 상속

- 부모의 `public` -> 자식에서는 `protected` 로 바뀜

- 외부에서는 접근할 수 없음

- 자식 클래스 내부나 그 하위 클래스에서만 접근 가능

```cpp
class Cat: protected Animal {
public:
    void act(void) {
        eat(); // 1
    } 
};
```

```cpp
// c.eat(); 2
c.act();
```

1. 내부에서 접근 가능

2. 외부에서 접근 불가

---

## `private` 상속

- 부모의 `public` , `protected` 멤버 -> 자식에서 모두 `private` 로 변경됨

- **자식**의 **자식**에서는 아예 접근 불가


```cpp
class Derived_dog : private Animal {
public:
    void eating(void) { // 1
        eat();
    } 

    void show(void) {
        cout << jong << '\n'; // 2
    }
};

class GrandChild_dog : public Derived_dog {
public:
    void display() {
        // eat();  // 3
    }
};
```

1. 가능, but 외부/자식에서는 불가

   ```cpp
   // dd.eat();
   dd.eating();
   dd.show();
   ```

2.  내부에선 가능

3. 자식의 자식은 접근 불가

---

| 방식       | 설명                                            |
| ----------- | --------------------------------------------- |
| `public`    | 가장 많이 사용됨. 부모의 멤버를 그대로 유지하여 자식이 외부에서도 사용 가능   |
| `protected` | 외부에는 감추고, 자식에서만 사용하도록 할 때 사용                  |
| `private`   | 외부와 자식의 자식에게 모두 숨기고, 자식 클래스 내부에서만 사용 가능하게 할 때 |

## 상속을 사용하는 이유

1. **코드 재사용**

   공통 기능을 부모에게 두고 자식이 사용하기 유용

   ---

2. **계층 구조 표현**

   *ex: 동물 -> 포유류 -> 개*

   ---

3. **유지보수 용이**

   기능 변경 시 부모 클래스만 수정하면 됨

   ---

4. **다형성과 함께 사용**

   [추상 클래스/ 가상 함수](https://github.com/BOLTB0X/c-cpp-study/tree/main/cpp/Classs03#abstract-class)와 결합해 유연하게 사용 가능

   ---

# Method Overloading과 Method Overriding

> 객체지향 프로그래밍에서 중요 개념

## 메서드 오버로딩 (Method Overloading)

- 같은 이름의 함수를 **매개변수(타입 or 개수)** 를 다르게해서 여러 개를 정의하는 것

- 컴파일 타임에 결정됨 -> **정적 바인딩( Static Binding)**

## 기본 사용법

```cpp
class Print {
public:
    void show(int a) {
        cout << "정수: " << a << '\n';
    }
    void show(double a) {
        cout << "실수: " << a << '\n';
    }
    void show(int a, int b) {
        cout << "두 정수: " << a << ", " << b << '\n';
    }
};
```

```cpp
p.show(10);       // show(int)
p.show(3.14);     // show(double)
p.show(1, 2);     // show(int, int)
```

## Function return types are not considered for uniqueness

> C++에서 함수 오버로딩은 함수 이름 + 매개변수의 타입/개수 로만 구분

**함수의 반환형(return type)** 은 구분 기준이 되지 않음

```cpp
int add(int a, int b) {
    return a + b;
}

// 컴파일 에러
double add(int a, int b) {
    return a + b;
}
```

- 다음과 같은 두 `add` 함수는 오버로딩으로 인정되지 않기 때문에 컴파일 에러가 발생

- 반환형은 구분에 포함되지 않은 이유

   - 함수 호출 시, 컴파일러는 함수 이름과 전달된 인자만 보고 어떤 함수인지 결정해야 함

   - 반환형은 함수 호출하는 쪽에서 생략될 수 있기 때문에, 구분 기준으로 삼을 수 없음

   ---

## 메서드 오버라이딩(Method Overriding)

- 상속 관계에서, 부모 클래스의 메서드를 자식 클래스가 **재정의하는 것**

- 실행 중 결정됨 **(-> 동적 바인딩, Dynamic Binding)**

## 기본 사용법

- 상속 관계 필요 (`Base` -> `Derived`)

- 부모 메서드와 함수 이름, 매개변수, 반환형이 완전히 같아야 함

- `virtual` 키워드 사용

- `override` 키워드(C++11 이후)는 명시적으로 오버라이딩을 표현


```cpp
class Animal {
public:
    virtual void sound() {
        cout << "동물의 소리는!?" << '\n';
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "멍멍!" << '\n';
    }
};
```

## 참고

- [블로그 참고 - hwan-shell(C++ 순수 가상 함수란? 추상 클래스란??(pure virtual function, abstract class))](https://hwan-shell.tistory.com/223)

- [learn C++ - 추상 클래스(C++)](https://learn.microsoft.com/ko-kr/cpp/cpp/abstract-classes-cpp?view=msvc-170)

- [TCP 스쿨 - 추상 클래스](https://www.tcpschool.com/cpp/cpp_polymorphism_abstract)

- [블로그 참고 - hexabrain(상속(Inheritance))](https://blog.hexabrain.net/173)

- [블로그 참고 - 개발하는 곰댕이(상속과 다형성에 대해 알아보자)](https://velog.io/@meong9090/c-%EC%83%81%EC%86%8D)

- [블로그 참고 - 소년코딩(함수 오버로딩 (Function overloading))](https://boycoding.tistory.com/221)

- [블로그 참고 - hexabrain(상속 오버라이딩(Inheritance Overriding))](https://blog.hexabrain.net/175)