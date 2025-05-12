#include <iostream>

using namespace std;

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

    int add(int a, int b) {
        return a + b;
    }

    // 컴파일 에러
    // double add(int a, int b) {
    //     return a + b;
    // }

    double add(double a, double b) {
        return a + b;
    }
};

int main(void) {
    Print p;
    p.show(10);       // show(int)
    p.show(3.14);     // show(double)
    p.show(1, 2);     // show(int, int)

    return 0;
}
