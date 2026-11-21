#include <iostream>>

using namespace std;

int main() {
    int a = 10;
    int* ptr = &a; // Pointer to integer
    int& ref = a;  // Reference to integer

    cout << "a Value: " << a << endl;
    cout << "Value via pointer: " << *ptr << endl;
    cout << "Value via reference: " << ref << endl;

    *ptr = 20;
    cout << "After modifying via pointer, value of a: " << a << endl;

    ref = 30;
    cout << "After modifying via reference, value of a: " << a << endl;

    return 0;
}