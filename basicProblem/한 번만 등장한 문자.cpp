#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> m;
    
    for (const char ch: s) {
        m[ch] += 1;
    }
    
    for (const pair<char, int> p: m) {
        //cout << p.first << ' ' << p.second << '\n';
        if (p.second == 1) {
            answer.push_back(p.first);
        }
    }
    return answer;
}