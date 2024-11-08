#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";
    
    for (int i = 0; i <= myString.size() - pat.size(); ++i) {
        string temp = myString.substr(i, pat.size());
        //cout << temp << ' ' << i << '\n';
        
        if (temp == pat) {
            answer = myString.substr(0, i + pat.size());
        }
    }
    return answer;
}