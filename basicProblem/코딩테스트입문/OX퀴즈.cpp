#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    vector<vector<string>> _quiz;
    
    for (const string st: quiz) {
        string temp;
        stringstream ss(st);
        vector<string> v;
        
        while (getline(ss, temp, ' ')) {
            v.push_back(temp);
        }
        
        _quiz.push_back(v);
    }
    
    for (const vector<string> v: _quiz) {
        if (v[1] == "-") {
            answer.push_back(stoi(v[0]) - stoi(v[2]) == stoi(v[4]) ? "O" : "X");
        } 
        
        else {
            answer.push_back(stoi(v[0]) + stoi(v[2]) == stoi(v[4]) ? "O" : "X");
        }
    }
    
    return answer;
}