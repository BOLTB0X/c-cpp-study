# RAII(Resource Acquisition Is Initialization)

>  **C++다운 C++ 프로그래밍을 위한 핵심**<br/>
> 리소스 획득이 곧 초기화(한국어로는 자원 획득은 초기화라는 의미로 설명 됌)

- 리소스(메모리, 파일, 락, 네트워크 등) 을 어떤 객체가 생성자에서 얻고

- 해당 객체의 소멸자에서 자원을 자동으로 해제하는 방식

**RAII는 "힙 메모리 포함 수동 자원들을 스택처럼 자동으로 해제되게 만드는 디자인 패턴"**

*cf.Resource은 단순히 메모리만 의미하지 않음*

- *동적 메모리*
- *파일 핸들*
- *네트워크 연결*
- *Mutex Lock*
- *GPU 리소스*
- *DirectX COM 객체*

## 왜 필요한가?

> Stack 메모리 영역에 저장되는 로컬 객체(= objects with automatic storage duration)의 생애는 컴파일러와 C++ 런타임에 의해 자동으로 관리<br/>사용자가 아무리 해제를 깜빡해도 위와 같은 객체의 생성자와 소멸자는 항상, 무슨 일이 있어도 실행<br/>하지만 heap 메모리는 아님

- 예외 발생 시에도 리소스가 **leak(누수)** 되지 않도록 보장

- 리소스 해제를 잊거나 중복으로 해제하는 오류를 방지

- C의 `malloc/free`, `fopen/fclose` 등 수동 해제 방식의 단점을 보완


| 항목        | 설명                             |
| --------- | ------------------------------ |
| **목표**    | 자원의 안전한 획득/해제                  |
| **언제 사용** | 메모리, 파일, 락, 네트워크 등             |
| **이점**    | 자원 누수 방지, 예외 안정성, 코드 간결성       |
| **적용 ex** | 스마트 포인터, `lock\_guard`, 파일 스트림 등 |


```cpp
// RAII가 없는 코드 ex)
void LoadTexture(bool failed)
{
    Texture* texture = new Texture();

    // 텍스처 로딩

    // 중간에 예외나 조기 반환 발생 가능
    if (failed)
        return;


    delete texture;
}
```

- 문제는 `delete`가 실행되기 전에 함수가 종료될 가능성이 있다는 것

- `failed`가 참이면 `delete`가 실행되지 않아도 **결국 Memory Leak이 발생**

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

### RAII의 동작 원리

1. **Resource Acquisition:** `std::make_unique<Texture>()`로 객체 생성 및 소유권 획득

2. **Resource Usage:** 소유한 객체를 안전하게 사용

3. **Scope Exit:** 함수 반환 또는 예외 발생

4. **Resource Release:** `unique_ptr` 소멸자가 객체를 자동으로 정리

**RAII는 단순히 스마트 포인터를 사용하는 기술이 아니라는 것을 명심**

**스마트 포인터는 RAII를 구현하는 대표적인 도구일 뿐이고, RAII 자체는 자원의 획득과 해제를 객체의 생성 및 소멸에 연결하는 설계 원칙**

---

## RAII 적용 사례

1. **스마트 포인터** : `std::unique_ptr`, `std::shared_ptr`

   ```cpp
   #include <memory>

   void LoadTexture(bool failed) {
        std::unique_ptr<Texture> texture = std::make_unique<Texture>();

        if (failed)
            return;
   }
   ```

   1. 생성 시 자원 획득

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

## 렌더러의 GPU 리소스 관리와 연결

1. 직접 관리하는 방식

    ```cpp
    ID3D12Resource* resource = nullptr;

    device->CreateCommittedResource(
        &heapProperties,
        D3D12_HEAP_FLAG_NONE,
        &desc,
        D3D12_RESOURCE_STATE_COMMON,
        nullptr,
        IID_PPV_ARGS(&resource)
    );

    // GPU 리소스 사용

    resource->Release();
    ```

    개발자가 `Release()` 호출 시점을 직접 관리해야 함

    호출을 빠뜨리면 리소스 누수가 발생할 수 있고, 너무 일찍 호출하면 유효하지 않은 리소스를 사용하게 될 수 있음

2. `ComPtr`를 사용하는 방식

    ```cpp
    Microsoft::WRL::ComPtr<ID3D12Resource> resource;

    device->CreateCommittedResource(
        &heapProperties,
        D3D12_HEAP_FLAG_NONE,
        &desc,
        D3D12_RESOURCE_STATE_COMMON,
        nullptr,
        IID_PPV_ARGS(&resource)
    );
    ```

    `ComPtr`가 소멸하면 내부 `COM` 객체의 참조 카운트를 감소시키고, 참조 카운트가 `0`이 되면 객체가 정리

---

## 참고

- [MSLearn - 개체 수명 및 리소스 관리(RAII)](https://learn.microsoft.com/ko-kr/cpp/cpp/object-lifetime-and-resource-management-modern-cpp?view=msvc-170)

- [SCRIPTS BY - 모던 C++의 핵심, RAII idiom이란 무엇인가](https://nx006.tistory.com/40)

- [computing-jhson - RAII 개념과 필요성](https://computing-jhson.tistory.com/131)
