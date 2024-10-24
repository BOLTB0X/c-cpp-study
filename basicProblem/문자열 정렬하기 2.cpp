#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for (const char ch: my_string) {
        if (ch >= 'A' && ch <= 'Z') {
            answer.push_back(ch + 32);
        }
        else {
            answer.push_back(ch);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}