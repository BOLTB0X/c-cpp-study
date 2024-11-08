#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for (char& ch: myString) {
        if (ch >= 'a' && ch <= 'z')
            ch -= 32;
    }
    return myString;
}