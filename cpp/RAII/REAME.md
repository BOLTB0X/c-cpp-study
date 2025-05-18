# RAII(Resource Acquisition Is Initialization)

>  **C++다운 C++ 프로그래밍을 위한 핵심**<br/>
> 리소스 획득이 곧 초기화

- 리소스(메모리, 파일, 락, 네트워크 등) 을 어떤 객체가 생성자에서 얻고

- 해당 객체의 소멸자에서 자원을 자동으로 해제하는 방식

**RAII는 "힙 메모리 포함 수동 자원들을 스택처럼 자동으로 해제되게 만드는 디자인 패턴"**

## 왜 필요한가?

> Stack 메모리 영역에 저장되는 로컬 객체(= objects with automatic storage duration)의 생애는 컴파일러와 C++ 런타임에 의해 자동으로 관리

> 사용자가 아무리 해제를 깜빡해도 위와 같은 객체의 생성자와 소멸자는 항상, 무슨 일이 있어도 실행

> 하지만 heap 메모리는 아님

- 예외 발생 시에도 리소스가 **leak(누수)** 되지 않도록 보장

- 리소스 해제를 잊거나 중복으로 해제하는 오류를 방지

- C의 `malloc/free`, `fopen/fclose` 등 수동 해제 방식의 단점을 보완


---
| 항목        | 설명                             |
| --------- | ------------------------------ |
| **목표**    | 자원의 안전한 획득/해제                  |
| **언제 사용** | 메모리, 파일, 락, 네트워크 등             |
| **이점**    | 자원 누수 방지, 예외 안정성, 코드 간결성       |
| **적용 ex** | 스마트 포인터, `lock\_guard`, 파일 스트림 등 |

---

## RAII 기본 메모리 관리

```cpp
class MyBuffer 
{
private:
    int* buffer;

public:
    MyBuffer(size_t size)
    {
        buffer = new int[size];  // 자원 획득
        std::cout << "버퍼 할당됨\n";
    }

    ~MyBuffer(void)
    {
        delete[] buffer;         // 자원 해제
        std::cout << "버퍼 해제됨\n";
    }

    void use(void)
    {
        buffer[0] = 123;
        std::cout << "버퍼 사용 중: " << buffer[0] << std::endl;
    }
};
```

```cpp
int main(void)
{
    MyBuffer buf(10);  // 1
    buf.use();         // 2

    return 0;
}  // 3
```

```
버퍼 할당됨
버퍼 사용 중: 123
버퍼 해제됨
```

1. 생성자에서 리소스 획득

2. 리소스 사용

3. 스코프 벗어나면 자동으로 소멸자 호출 -> 리소스 해제

## RAII 적용 사례

1. **스마트 포인터** : `std::unique_ptr`, `std::shared_ptr`

   ```cpp
   void foo(void) {
        std::unique_ptr<int> ptr(new int(42));  // 1

        return  // 2
   }
   ```

   1.  생성 시 자원 획득

   2. 자동으로 `delete` 호출됨

   ---

2. **뮤텍스 락** : `std::mutex`

   ```cpp
   std::mutex mtx;
   
   void critical_section() {
        std::lock_guard<std::mutex> lock(mtx);  // 1
        
        return // 2
    }
   ```

   1. 락 획득

   2. 락 해제는 자동으로 소멸자에서 수행됨

   ---

3. **STL도 RAII 기반**

   - `std::fstream` : 파일을 열면 생성자에서 열고, 소멸자에서 자동으로 닫힘

   - `std::vector` , `std::string` : 내부 메모리 자동 관리

   ---

## 참고

- [MSLearn - 개체 수명 및 리소스 관리(RAII)](https://learn.microsoft.com/ko-kr/cpp/cpp/object-lifetime-and-resource-management-modern-cpp?view=msvc-170)

- [SCRIPTS BY - 모던 C++의 핵심, RAII idiom이란 무엇인가](https://nx006.tistory.com/40)

- [computing-jhson - RAII 개념과 필요성](https://computing-jhson.tistory.com/131)
