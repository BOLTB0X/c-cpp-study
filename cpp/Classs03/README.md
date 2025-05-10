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

## 참고

- [블로그 참고 - hwan-shell(C++ 순수 가상 함수란? 추상 클래스란??(pure virtual function, abstract class))](https://hwan-shell.tistory.com/223)

- [learn C++ - 추상 클래스(C++)](https://learn.microsoft.com/ko-kr/cpp/cpp/abstract-classes-cpp?view=msvc-170)

- [TCP 스쿨 - 추상 클래스](https://www.tcpschool.com/cpp/cpp_polymorphism_abstract)