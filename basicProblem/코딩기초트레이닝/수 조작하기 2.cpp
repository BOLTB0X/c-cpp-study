#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numLog) {
    string answer = "";
    
    for (int i = 1; i < numLog.size(); ++i) {
        char ch;
        
        if (numLog[i] - numLog[i-1] == 1)
            ch = 'w';
        
        else if (numLog[i] - numLog[i-1] == -1)
            ch = 's';
        
        else if (numLog[i] - numLog[i-1] == 10)
            ch = 'd';
        
        else if (numLog[i] - numLog[i-1] == -10) 
            ch = 'a';
        
        answer.push_back(ch);
    }
    
    return answer;
}