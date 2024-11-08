#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for (char& ch: myString) {
        if (ch == 'a') ch = 'A';
        else if (ch != 'A' && ch >= 'A' && ch <= 'Z') ch += 32;
    }
    return myString;
}