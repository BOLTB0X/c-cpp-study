# namespace

> 서로 다른 코드에서 같은 이름을 사용할 때 생길 수 있는 이름 충돌을 방지하고, 코드의 가독성과 유지 보수성을 높이는 역할

## namespace 사용 목적

1. 이름 충돌 방지
   네임스페이스는 다른 라이브러리나 코드와 이름이 겹칠 때 이를 피하기 위해 사용
   <br/>

2. 코드의 모듈화
   서로 관련 있는 함수나 변수를 같은 네임스페이스로 묶어 놓는다면 코드를 더 잘 구성이 가능
   <br/>

3. 가독성과 관리
   이름에 대한 별도의 범위를 제공하여 코드의 의도를 명확히 하고 관리 용이
   <br/>

## 기본 예시

```cpp
namespace My_Namespace {
    int value = 31;

    void show() {
        std::cout << "Hello My_Namespace!" << '\n';
    }
}

int main() {
    std::cout << My_Namespace::value << std::'\n'; // 31
    My_Namespace::show(); // Hello My_Namespace!
    return 0;
}
```

## using namespace

> 특정 네임스페이스에 정의된 이름들을 여러 번 사용해야 할 경우 'using namespace' 사용

using namespace 구문을 통해 코드에서 namespace를 생략 가능

```cpp
using namespace My_Namespace;

int main() {
    std::cout << age << '\n'; // 31
    show(); // Hello My_Namespace!
    return 0;
}
```

## 중첩 namespace

namespace 안에 다른 namespace 정의 가능

```cpp
namespace A_Namespace {
    namespace B_Namespace {
        void show() {
            std::cout << "Hello A_Namespace::B_Namespace" << '\n';
        }
    }
}

int main() {

    A_Namespace::B_Namespace::show(); // Hello A_Namespace::B_Namespace
    return 0;
}
```

## 별칭

```cpp
namespace Alias = A_Namespace::B_Namespace;
```

## anonymous(unnamed) namespace

> 변수의 중복 문제같이 현재 cpp 파일내에서만 사용할 경우

가독성을 위해 사용하는 접근 가능한 네임스페이스

```cpp
namespace {
    int age = 33;

    void show() {
        std::cout << "anonymous(unnamed)" << std::endl;
    }
}

namespace Alias = A_Namespace::B_Namespace;

int main() {
    Alias:: show(); // Hello A_Namespace::B_Namespace
    show(); // anonymous(unnamed)
    return 0;
}
```

## std

> C++에서 사용하는 표준 네임스페이스로, C++ 표준 라이브러리에 정의된 함수, 클래스, 객체 등을 포함

C++ 프로그램에서 자주 사용되는 기능을 제공

- **컨테이너**
  벡터(std::vector), 리스트(std::list), 맵(std::map), 셋(std::set) 등
  <br/>

- **알고리즘**
  정렬(std::sort), 검색(std::find), 수학 메서드(std::max, std::min 등)
  <br/>

- **입출력 스트림**
  표준 입력(std::cin), 표준 출력(std::cout), 파일 입출력(std::ifstream, std::ofstream 등)
  <br/>
- **문자열 처리**
  문자열 클래스인 std::string과 문자열 관련 메서드
  <br/>

## 참고

- [MS-Learn-Namespace(C++)](https://learn.microsoft.com/ko-kr/cpp/cpp/namespaces-cpp?view=msvc-170)

- [블로그-개발자 지망생([C++] namespace 네임스페이스 정리 및 예제)](https://blockdmask.tistory.com/474)

- [블로그-감자는 맛있다([C++] 익명 네임스페이스, anonymous(unnamed) namespac)](https://jogamja.tistory.com/121)
