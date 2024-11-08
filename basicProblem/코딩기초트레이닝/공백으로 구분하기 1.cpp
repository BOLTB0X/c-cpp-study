#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string temp;
    stringstream ss(my_string);
    
    while (getline(ss, temp, ' ')) {
        answer.push_back(temp);
    }
    return answer;
}