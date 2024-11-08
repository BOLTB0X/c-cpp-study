#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    for (char& ch: myString) {
        if (ch >= 'A' && ch <= 'Z')
            ch += 32;
    }
    return myString;
}