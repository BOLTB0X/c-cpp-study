#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    int mode = 0;
    
    for (int i = 0; i < code.size(); ++i) {
        if (!mode) {
            if (code[i] == '1') {
                mode = 1;
            } 
            else if (i % 2 == 0) 
                answer.push_back(code[i]);
        }
        
        else {
            if (code[i] == '1') {
                mode = 0;
            } 
            else if (i % 2) 
                answer.push_back(code[i]);
        }
    }
    return answer.empty() ? "EMPTY" : answer;
}