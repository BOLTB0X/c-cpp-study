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

class Animal {
public:
    virtual void eat(void) { 
        cout << "먹는 중\n"; 
    }
};
    
class Dog : public Animal {
public:

    void eat(void) override {
        cout << "우걱우걱 " << "먹는 중\n"; 
    }
    void bark(void) { 
        cout << "멍멍!\n"; 
    }
};

class Printer {
public:
    void print(int num) {
        cout << "정수: " << num << endl;
    }
        
    void print(double num) {
        cout << "실수: " << num << endl;
    }
    
    void print(string text, int count) {
        for (int i = 0; i < count; i++) {
            cout << "문자열: " << text << endl;
        }
    }
};

int main(void) {
    MyClass obj;
    // obj.a = 1; x
    // obj.b = 2; x
    // obj.c = 3; x
    obj.d = 4;

    Dog dog;

    //dog.eat(); // 먹는 중
    dog.bark(); //  멍멍!


    Printer printer;

    printer.print(2); // 정수: 2
    printer.print(2.5); // 실수: 2.5
    printer.print("Two", 1); // 문자열: Two

    dog.eat(); // 우걱우걱 먹는 중

    return 0;
}