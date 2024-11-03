#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for (const int a: arr) {
        if (a >= 50 && !(a % 2))
            answer.push_back(a / 2);
        else if (a < 50 && a % 2)
            answer.push_back(a * 2);
        else
            answer.push_back(a);
    }
    
    return answer;
}