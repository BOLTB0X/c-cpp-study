#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (const char ch: my_string) {
        if (ch >= 'a' && ch <= 'z') {
            answer.push_back(ch - 32);
        } else if (ch >= 'A' && ch <= 'Z') {
            answer.push_back(ch + 32);
        }
    }
    
    return answer;
}