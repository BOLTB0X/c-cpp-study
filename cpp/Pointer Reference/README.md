# Pointer & Reference

> [Pointer Basic](https://github.com/BOLTB0X/c-cpp-study/tree/main/c/pointer1), [Memory](https://github.com/BOLTB0X/c-cpp-study/tree/main/cpp/Memory)

## Review

**Pointer는 다른 객체의 메모리 주소를 저장하는 변수**

```cpp
int value = 10;

int* ptr = &value;
```

- `value`: 정수 10을 저장하는 객체

- `&value`: `value` 객체의 메모리 주소

- `ptr`: `value`의 주소를 저장하는 포인터 변수

- `*ptr`: `ptr`이 가리키는 객체에 접근하는 표현식

---

## Reference 란 ?

**C++에서 Reference는 기존 객체에 부여하는 또 다른 이름(별칭, Alias)이라는 개념**

```cpp
int a = 10;

int& ref = a; // ref는 a를 참조하는 이름
```

```cpp
ref = 30;
cout << "After modifying via reference, value of a: " << a << endl;
```

`ref`에 값을 대입했지만 실제로 변경되는 것은 `a` 객체

**즉, 참조는 별도의 독립적인 객체를 만드는 것이 아니라 기존 객체에 접근하는 별칭(Alias)을 제공하는 개념***

---

## Pointer와 Reference 의 핵심 차이

| 구분 | Pointer | Reference |
| :--- | :--- | :--- |
| **선언** | `*` | `&` |
| **초기화** | 나중에도 가능 | 선언 시 초기화 필요 |
| **대상 변경** | 가능 | 다른 객체로 재지정 불가 |
| **Null** | `nullptr` 가능 | 정상적인 참조는 불가능 |
| **접근** | `*ptr` | `ref` |
| **주소 접근** | `ptr` 자체가 주소 | `&ref`는 대상 객체의 주소 |

1. **포인터는 다른 대상을 가리키도록 변경할 수 있음**

    ```cpp
    *ptr = 20;
    cout << "After modifying via pointer, value of a: " << a << endl; // 29
    ```

2. **참조는 초기화된 대상을 바꿀 수 없음**

    ```cpp
    ref = 30;
    cout << "After modifying via reference, value of a: " << a << endl; // 10
    ```

---

## 함수 인자에서의 활용

1. **객체를 값으로 전달받는 경우**

    ```cpp
    void UpdateCamera(Camera camera)
    {
        camera.position.x = 10.0f;
    }
    ```

    일반적으로 원본 객체의 복사본을 사용하게 됌, **원본 `Camera`는 변경되지 않음**

2. **참조를 사용하면**

    ```cpp
    void UpdateCamera(Camera& camera)
    {
        camera.position.x = 10.0f;
    }
    ```

3. **포인터를 사용하면**

    ```cpp
    void UpdateCamera(Camera* camera)
    {
        if (camera == nullptr)
            return;

        camera->position.x = 10.0f;
    }
    ```

    ```cpp
    Camera camera;

    UpdateCamera(camera);  // Reference
    UpdateCamera(&camera); // Pointer
    ```

---

## `const`와 함께 사용하기

```cpp
void Render(const Camera& camera);
```

선언은 다음 의미를 가짐

- `Camera` 객체를 복사하지 않고 참조한다.
- 함수 내부에서 `Camer` `를 수정할 수 없다.
- 원본 객체를 읽기 위한 용도로 사용한다.

```cpp
class Renderer
{
public:
    void Render(const Camera& camera);
    void UpdateCamera(Camera* camera);
};
```

- `Render(const Camera&)`: `Camera`를 읽기만 한다.
- `UpdateCamera(Camera*)`: `Camera`를 수정할 수 있고, 전달된 포인터가 `nullptr`일 가능성도 고려

**Reference를 사용하기 좋은 경우**

- 객체가 반드시 존재해야 함
- `nullptr`이 허용되지 않음
- 다른 객체를 참조하도록 변경할 필요가 없음
- 읽기 전용 전달이라면 `const T&`


**Pointer를 사용하기 좋은 경우**

- `nullptr`이 의미 있는 상태임
- 객체가 없을 수도 있음
- 가리키는 대상을 변경해야 함
- 소유권이나 수명 관계를 명시적으로 설계해야 함

```cpp
const int* p1;
int* const p2 = nullptr;
const int* const p3 = nullptr;
```


| 선언 | 주소 변경 | 대상 값 변경 |
| :--- | :--- | :--- |
| `const int* p1` | 가능 | 불가능 |
| `int* const p2` | 불가능 | 가능 |
| `const int* const p3` | 불가능 | 불가능 |

1. `const int* p1`

    ```cpp
    int a = 10;
    int b = 20;

    const int* p1 = &a;

    p1 = &b;  // 가능
    //*p1 = 30; // 불가능
    ```

2. `int* const p2`

    ```cpp
    int a = 10;

    int* const p2 = &a;

    // p2 = &b; // 불가능
    *p2 = 30;   // 가능
    ```

3. `const int* const p3`

    - `const int*` : 대상이 `const`

    - `int* const`: 포인터가 `const`

    - `const int* const`: 둘 다 `const`

---

