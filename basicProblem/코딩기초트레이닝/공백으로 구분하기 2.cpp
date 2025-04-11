#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string temp = "";
    stringstream ss(my_string);
    
    while (getline(ss, temp, ' ')) {
        if (temp.empty()) continue;
        answer.push_back(temp);
    }
    return answer;
}