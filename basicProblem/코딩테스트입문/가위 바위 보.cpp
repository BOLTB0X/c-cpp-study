#include <string>
#include <vector>

using namespace std;

string solution(string rsp) {
    string answer = "";
    
    for (const char ch: rsp) {
        switch (ch) {
            case '2':
                answer.push_back('0');
                break;
            case '0':
                answer.push_back('5');
                break;
            case '5':
                answer.push_back('2');
                break;
            default:
                break;
        }
    }
    
    return answer;
}