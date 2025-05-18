# Smart Pointer

>  C++의 현대적인 메모리 관리 방식인 **스마트 포인터(Smart Pointer)** 와 **RAII**

- **스마트 포인터(Smart Pointer)** 는 포인터 처럼 동작하지만, 메모리를 직접 관리하는 것이 아니라 **RAII(Resource Acquisition Is Initialization)** 원칙을 사용해 메모리를 자동으로 관리

- 객체가 생성될 대 자원을 할당, 객체가 소멸될 때 자원을 해제


## 스마트 포인터(Smart Pointer) 란?

> C++의 특별한 클래스 타입으로, **포인터** 처럼 동작하지만 스스로 메모리를 관리

- **포인터(Pointer)의 문제점**

   ```cpp
   int* ptr = new int(10);
   // ...

   delete ptr; // 실수로 안하면 메모리 누수
   ```

   이런 실수를 방지 하기위해 등장한 것이 **자동 메모리 관리** 해주는 포인터 -> **스마트 포인터**

   ---

- **작동 원리**

   - 기본적으로 템플릿 클래스, 포인터와 동일한 방식으로 사용

   - **소유권** 개념을 도입하여 메모리 접근 및 관리

   ---

- **개요** : `memory` 헤더에 존재

   | 스마트 포인터      | 설명                        |
   | ------------ | ------------------------- |
   | `unique_ptr` | 하나의 소유자만 허용 (단독 소유)       |
   | `shared_ptr` | 참조 카운트 기반 공유 소유           |
   | `weak_ptr`   | `shared_ptr`의 순환 참조 방지 용도 |

   ---

## `unique_ptr` : 단독 소유

1. **유일한 포인터(unique ptr)**

   ```cpp
   std::unique_ptr<int> uptr = std::make_unique<int>(100);
   std::unique_ptr<int> uptr2 = uptr; // 컴파일 에러 
   ```

   - 동일한 메모리를 가리키는 두개의 `std::unique_ptr` 인스턴스가 동시에 존재할수 없음
   
   - `delete` 호출이 필요 X -> 블록 벗어나면 자동 해제

   ---

2. **소유권 이전 (move semantics)**

   ```cpp
   std::unique_ptr<int> uptr = std::make_unique<int>(100);
   std::cout << *uptr << std::endl;  // 100

   // 소유권 이전 (move semantics)
   std::unique_ptr<int> uptr2 = std::move(uptr);
   // uptr 은 이제 null 상태
   ```
 
   - `std::move()` 통해서만 소유권 이동 가능

   - `uprt2` : 유일 소유

   ---

## `shared_ptr` : 공유 소유

1. **'공유' 소유권을 제공하는 포인터**

   ```cpp
   std::shared_ptr<int> sp1 = std::make_shared<int>(100);
   std::shared_ptr<int> sp2 = sp1; // 가능
   ```

   - 여러 스마트 포인터가 같은 객체를 공유

   - 마지막 **참조** 가 사라질 때 객체가 삭제됨

   ---

2. **참조 카운트**

   - 내부적으로 레퍼런스 카운팅을 수행하여 `std::shared_ptr` 인스턴스의 수를 추척

   - `sp1` , `sp2` 모두 동일한 메모리를 가리키며, **레퍼런스 카운트** : `2`

   - **레퍼런스 카운트** 가 `0` 이 되면 메모리 헤제

   ---

## `weak_ptr` : 참조는 하되 소유하지 않음

> `std::shared_ptr` 의 동반자

1. `shared_ptr` **만 사용할 때 발생하는 문제**

   ```cpp
   struct B; // 전방 선언

   struct A {
       std::shared_ptr<B> b_ptr;
   };

   struct B {
       std::shared_ptr<A> a_ptr;
   };
   ```

   ```cpp
   std::shared_ptr<A> a = std::make_shared<A>();
   std::shared_ptr<B> b = std::make_shared<B>();
   
   a->b_ptr = b;
   b->a_ptr = a;  // 소유권을 넘겨주면서 순환 참조 발생

   return 0;  // 메모리 누수 발생
   ```
   
   - `a` 와 `b` 는 서로를 `shared_ptr` 로 참조해서, **참조 카운트** 가 `0` 이 되지 않음

   - `main()`이 종료 되어도 `shared_ptr`이 서로를 참조하기 때문에 `delete` 가 절대 호출되지 않음

   - 결과적으로 **메모리 누수(memory leak)** 발생

   ---

2. `weak_ptr` 존재 이유

   ```cpp
   struct A {
       std::shared_ptr<B> b_ptr;
   };

   struct B {
       std::weak_ptr<A> a_ptr;  // 순환 참조 방지
   };
   ```

   ```cpp
   std::shared_ptr<A> a = std::make_shared<A>();
   std::shared_ptr<B> b = std::make_shared<B>();
   
   a->b_ptr = b;
   b->a_ptr = a;  // weak_ptr로 참조하므로, 순환 X
   ```

   - `weak_ptr` 참조 카운트를 증가 X

   - 결국 참조 카운트가 `0` 이 되면 `A` , `B` 둘 다 메모리에서 정상적으로 해제

   ---

3. `lock()`

   > 왜 `.lock()` 해서 "승격"해야 할까?

   - `weak_ptr`은 실제 객체를 소유하지 않기 때문

   - **바로 객체에 접근할 수 없고, 반드시 `shared_ptr` 로 일시적으로 변환(lock)**

   ```cpp
   std::shared_ptr<int> sp = std::make_shared<int>(42);
   std::weak_ptr<int> wp = sp;

   if (auto spt = wp.lock()) { // shared_ptr로 잠시 승격
       std::cout << *spt << std::endl;
   }
   ```

   - `weak_ptr`이 참조하던 객체가 이미 소멸될 수 있음

   - `.lock()`은 `shared_ptr`이 유효할 때만 유효한 **smart pointer** 를 반환하고, 그렇지 않으면 nullptr을 반환

   ---

## 참고

- [gdngy의 함께 만들어가는 테크노트 - 스마트 포인터](https://gdngy.tistory.com/183)

- [MS Learn - 스마트포인터](https://learn.microsoft.com/ko-kr/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170)

- [min-zero - 템플릿 - 스마트 포인터](https://min-zero.tistory.com/entry/C-STL-1-3-%ED%85%9C%ED%94%8C%EB%A6%BF-%EC%8A%A4%EB%A7%88%ED%8A%B8-%ED%8F%AC%EC%9D%B8%ED%84%B0smart-pointer)

- [kkado - 스마트 포인터(smart pointer) 란?](https://velog.io/@dltmdrl1244/C-%EC%8A%A4%EB%A7%88%ED%8A%B8-%ED%8F%AC%EC%9D%B8%ED%84%B0smart-pointer-%EB%9E%80)