#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    string temp;
    
    for (const char ch: my_string) {
        if (ch >= '0' && ch <= '9') 
            temp.push_back(ch);
        else {
            if (!temp.empty()) {
                answer += stoi(temp);
                temp = "";
            }
        }
    }
    
    if (!temp.empty()) answer += stoi(temp);
    
    return answer;
}