#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str, answer;
    cin >> str;
    
    for (const char ch: str) {
        if (ch >= 'A' && ch <= 'Z') {
            answer.push_back(ch + 32);
        } else if (ch >= 'a' && ch <= 'z') {
            answer.push_back(ch - 32);
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}