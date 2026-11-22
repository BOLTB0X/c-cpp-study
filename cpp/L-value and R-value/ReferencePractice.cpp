
#include <iostream>
#include <memory>
#include <string>
#include <utility>

// ============================================================
// 1. L-value / R-value 판별
// ============================================================

void CheckValue(int& value)
{
    std::cout << "L-value Reference\n";
}

void CheckValue(int&& value)
{
    std::cout << "R-value Reference\n";
}

// ============================================================
// 2. Copy / Move 동작 확인용 클래스
// ============================================================

class Buffer
{
public:
    explicit Buffer(size_t size)
        : size(size), data(new int[size])
    {
        std::cout << "[Constructor] Buffer Created\n";

        for (size_t i = 0; i < size; ++i)
            data[i] = static_cast<int>(i);
    }

    // Copy Constructor
    Buffer(const Buffer& other)
        : size(other.size), data(new int[other.size])
    {
        std::cout << "[Copy Constructor]\n";

        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    // Move Constructor
    Buffer(Buffer&& other) noexcept
        : size(other.size), data(other.data)
    {
        std::cout << "[Move Constructor]\n";

        other.size = 0;
        other.data = nullptr;
    }

    // Copy Assignment
    Buffer& operator=(const Buffer& other)
    {
        std::cout << "[Copy Assignment]\n";

        if (this == &other)
            return *this;

        int* newData = new int[other.size];

        for (size_t i = 0; i < other.size; ++i)
            newData[i] = other.data[i];

        delete[] data;

        data = newData;
        size = other.size;

        return *this;
    }

    // Move Assignment
    Buffer& operator=(Buffer&& other) noexcept
    {
        std::cout << "[Move Assignment]\n";

        if (this == &other)
            return *this;

        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        return *this;
    }

    ~Buffer()
    {
        std::cout << "[Destructor] Buffer Destroyed\n";
        delete[] data;
    }

    void Print() const
    {
        std::cout << "Buffer Size: " << size << '\n';
    }

private:
    size_t size = 0;
    int* data = nullptr;
};

// ============================================================
// 3. R-value를 반환하는 함수
// ============================================================

Buffer CreateBuffer()
{
    return Buffer(5);
}

// ============================================================
// 4. Main
// ============================================================

int main()
{
    std::cout << "\n========== 1. L-value / R-value ==========\n";

    int a = 10;

    CheckValue(a);       // L-value
    CheckValue(100);     // R-value
    CheckValue(a + 20);  // R-value

    std::cout << "\n========== 2. Reference ==========\n";

    int value = 10;

    int& lRef = value;
    const int& constRef = 100;
    int&& rRef = 200;

    lRef = 20;

    std::cout << "value: " << value << '\n';
    std::cout << "constRef: " << constRef << '\n';
    std::cout << "rRef: " << rRef << '\n';

    // 주의: 이름이 있는 r-value reference 변수는
    // 표현식으로 사용될 때 L-value이다.
    CheckValue(rRef);
    CheckValue(std::move(rRef));

    std::cout << "\n========== 3. Copy Constructor ==========\n";

    Buffer bufferA(10);

    Buffer bufferB = bufferA;

    bufferA.Print();
    bufferB.Print();

    std::cout << "\n========== 4. Move Constructor ==========\n";

    Buffer bufferC = std::move(bufferA);

    bufferA.Print();
    bufferC.Print();

    std::cout << "\n========== 5. Move Assignment ==========\n";

    Buffer bufferD(3);

    bufferD = std::move(bufferC);

    bufferC.Print();
    bufferD.Print();

    std::cout << "\n========== 6. Return Value ==========\n";

    Buffer bufferE = CreateBuffer();

    bufferE.Print();

    std::cout << "\n========== 7. unique_ptr Move ==========\n";

    std::unique_ptr<int> ptrA =
        std::make_unique<int>(100);

    std::unique_ptr<int> ptrB =
        std::move(ptrA);

    std::cout << "ptrA: "
              << (ptrA ? "Valid" : "nullptr") << '\n';

    std::cout << "ptrB: "
              << (ptrB ? "Valid" : "nullptr") << '\n';

    std::cout << "ptrB Value: " << *ptrB << '\n';

    std::cout << "\n========== Program End ==========\n";

    return 0;
}
