#include <iostream>

using namespace std;

class Person
{
public:
    string name;
    int age;

    // 생성자 (Constructor)
    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    void introduce()
    {
        cout << "Hi, I'm " << name << " and I'm " << age << " years old." << endl;
    }
};

class Dog
{
public:
    string name;
    int age;

    // 생성자 1
    Dog()
    {
        name = "무명";
        age = 0;
    }

    // 생성자 2
    Dog(string n, int a)
    {
        name = n;
        age = a;
    }

    void info()
    {
        cout << name << " : " << age << "살" << endl;
    }
};

class Student
{
    string name;
    int grade;

public:
    Student(string n, int g) : name(n), grade(g)
    {
        // 초기화 리스트를 사용하면 가독성이 높음
    }

    void print()
    {
        cout << name << "의 학년은 " << grade << "학년입니다." << endl;
    }
};

class Book
{
public:
    Book()
    {
        cout << "기본 생성자 호출됨~" << endl;
    }
};

class ClassName {
public:
    ClassName() {
        cout << "생성자 호출!" << endl;
    }
    
    ~ClassName() { 
        cout << "소멸자 호출!" << endl;
    }
};

class MyArray {
    int* arr;

public:
    MyArray(int size) {
        arr = new int[size]; // 동적 할당
        cout << "배열 할당됨" << endl;
    }

    ~MyArray() {
        delete[] arr; // 해제
        cout << "배열 해제됨" << endl;
    }
};

int main(void)
{
    Person p("B0X", 65);
    // p.name = "B0X";
    // p.age = 55;
    p.introduce(); // Hi, I'm B0X and I'm 55 years old.
    // Hi, I'm B0X and I'm 65 years old.

    Dog d1;
    Dog d2("코코", 3);

    d1.info(); // 이름 없음 : 0살
    d2.info(); // 코코 : 3살

    Student st("테리", 6);

    st.print();

    ClassName cn;
    // 생성자 호출!
    // 소멸자 호출!

    MyArray a(5);
    // 배열 할당됨
    // 배열 해제됨
    return 0;
}