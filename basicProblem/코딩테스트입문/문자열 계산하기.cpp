#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    vector<string> v;
    string temp;
    stringstream ss(my_string);
    
    while (getline(ss, temp, ' ')) {
        v.push_back(temp);
    }
    
    answer += stoi(v.front());
    
    for (int i = 1; i < v.size(); i += 2) {
        if (v[i] == "+") {
            answer += stoi(v[i+1]);
        } else {
            answer -= stoi(v[i+1]);
        }
    }
    
    return answer;
}