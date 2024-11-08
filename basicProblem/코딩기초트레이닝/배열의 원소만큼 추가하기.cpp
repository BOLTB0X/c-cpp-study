#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (const int a: arr) {
        vector<int> temp(a, a);
        answer.insert(answer.end(), temp.begin(), temp.end());
    }
    return answer;
}