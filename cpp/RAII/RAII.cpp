#include <iostream>

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

int main(void)
{
    MyBuffer buf(10);  // 생성자에서 리소스 획득
    buf.use();         // 리소스 사용

    return 0;
}  // 스코프 벗어나면 자동으로 소멸자 호출 → 리소스 해제
