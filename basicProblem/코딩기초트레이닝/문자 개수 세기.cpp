#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    
    for (const char ch : my_string) {
        if (ch >= 'A' && ch <= 'Z') {
            answer[ch - 'A'] += 1;
        }
        else {
            answer[ch - 'a' + 26] += 1;
        }
    }
    return answer;
}