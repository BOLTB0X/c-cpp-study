#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (const char ch: my_string) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') continue;
        answer.push_back(ch);
    }
    
    return answer;
}