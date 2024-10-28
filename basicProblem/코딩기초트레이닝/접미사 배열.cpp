#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    int size = my_string.size();
    
    for (int i = 0; i < size; ++i) {
        answer.push_back(my_string.substr(size - 1 - i));
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}