#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string alp) {
    for (char& ch: my_string) {
        if (ch == alp[0]) {
            if (ch >= 'A' && ch <= 'Z')
                continue;
            ch -= 32;
        }
    }
    return my_string;
}