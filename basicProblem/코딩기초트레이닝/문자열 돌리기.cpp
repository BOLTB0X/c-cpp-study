#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for (const char ch: str) {
        cout << ch << '\n';
    }
    return 0;
}