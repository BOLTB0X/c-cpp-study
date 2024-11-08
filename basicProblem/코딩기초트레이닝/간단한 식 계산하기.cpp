#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string binomial) {
    int answer = 0;
    vector<string> bino;
    string temp = "";
    stringstream ss(binomial);
    
    while (getline(ss, temp, ' ')) {
        bino.push_back(temp);
    }
    
    answer += stoi(bino[0]);
    
    // for (const string b: bino) {
    //     cout << b << '\n';
    // }
    
    for (int i = 1; i < bino.size(); i += 2) {
        if (bino[i] == "+") 
            answer += stoi(bino[i+1]);
        
        else if (bino[i] == "-")
            answer -= stoi(bino[i+1]);
        
        else if (bino[i] == "*")
            answer *= stoi(bino[i+1]);
    }
    
    return answer;
}