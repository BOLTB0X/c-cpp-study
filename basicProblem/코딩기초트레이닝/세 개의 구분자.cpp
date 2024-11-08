#include <string>
#include <vector>

using namespace std;

vector<string> solution(string myStr) {
    vector<string> answer;
    string temp = "";
    
    for (const char ch: myStr) {
        if (ch == 'a' || ch == 'b' || ch == 'c') {
            if (temp.empty())
                continue;
            answer.push_back(temp);
            temp = "";
        } 
        else {
            temp.push_back(ch);
        }
    }
    
    if (!temp.empty()) answer.push_back(temp);
    
    if (answer.empty()) answer = { "EMPTY" };
    return answer;
}