#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<int> v;
    string temp = "";
    
    for (const char ch: s) {
        if (ch == ' ') {
            if (temp.empty()) continue;
            v.push_back(stoi(temp));
            temp = "";
        }
        
        else if (ch == 'Z') {
            if (v.empty()) continue;
            v.pop_back();
        }
        
        else {
            temp.push_back(ch);
        }
    }
    
    if (temp.size()) {
        v.push_back(stoi(temp));
    }
    
    for (const int ele: v) {
        answer += ele;
    }
    
    return answer;
}