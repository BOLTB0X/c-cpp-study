#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    for (const string str: intStrs) {
        string temp = str.substr(s, l);
        
        if (stoi(temp) > k) answer.push_back(stoi(temp));
    }
    return answer;
}