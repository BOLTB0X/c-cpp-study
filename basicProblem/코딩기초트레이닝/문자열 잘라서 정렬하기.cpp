#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> solution(string myString) {
    vector<string> answer;
    string temp = "";
    stringstream ss(myString);
    
    while (getline(ss, temp, 'x')) {
        if (temp.empty()) continue;
        answer.push_back(temp);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}