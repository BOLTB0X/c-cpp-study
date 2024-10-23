#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    
    for (const char ch: to_string(age)) {
        answer.push_back(ch - '0' + 'a');
    }
    
    return answer;
}