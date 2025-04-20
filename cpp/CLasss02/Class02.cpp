#include <iostream>

using namespace std;

class BankAccount {
private:
    int balance;
    
public:
    void deposit(int amount) {
        if (amount > 0) balance += amount;
    }
    
    int getBalance() {
        return balance;
    }
};

class MyClass {
    int a; // 디폴트 -> private
private:
    int b;
protected:
    int c;
public:
    int d;

    void show() {
        a = 1; // 가능
        b = 2; // 가능
        c = 3; // 가능
        d = 4; // 가능
    }
};

class SubClass : public MyClass {
    void accessTest() {
        // a = 1; x (private이므로 접근 불가)
        // b = 2; x (private이므로 접근 불가)
        c = 3;    // o (protected → 자식 클래스 접근 가능)
        d = 4;   // o (public)
    }
};

class Car {
public:
    void drive();  // 사용자가 호출하는 것
    void powerOnOff();  // 사용자가 호출하는 것
private:
    void injectFuel();
    void igniteEngine();
};

int main(void) {
    MyClass obj;
    // obj.a = 1; x
    // obj.b = 2; x
    // obj.c = 3; x
    obj.d = 4;
    return 0;
}