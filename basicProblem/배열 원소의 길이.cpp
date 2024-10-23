#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    
    for (const string st: strlist) {
        answer.push_back(st.size());
    }
    
    return answer;
}