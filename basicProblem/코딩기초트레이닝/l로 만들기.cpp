#include <string>
#include <vector>

using namespace std;

string solution(string myString) {
    string answer = "";
    for (const char ch: myString) {
        if (ch <= 'l') {
            answer.push_back('l');
        } else {
            answer.push_back(ch);
        }
    }
    return answer;
}