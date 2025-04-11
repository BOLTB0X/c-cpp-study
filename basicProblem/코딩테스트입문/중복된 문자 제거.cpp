#include <string>
#include <vector>

using namespace std;

bool contains(string st, char target) {
    for (const char ch: st) {
        if (ch == target) return 1;
    }
    return 0;
}

string solution(string my_string) {
    string answer = "";
    
    for (const char ch: my_string) {
        if (contains(answer, ch)) continue;
        answer.push_back(ch);
    }
    
    return answer;
}