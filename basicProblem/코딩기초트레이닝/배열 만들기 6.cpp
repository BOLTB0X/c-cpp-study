#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int i = 0;
    
    while (i < arr.size()) {
        if (answer.empty())
            answer.push_back(arr[i++]);
        else {
            if (answer.back() == arr[i]) {
                answer.pop_back();
                i++;
            }
            else if (answer.back() != arr[i])
                answer.push_back(arr[i++]);
        }
    }
    
    if (answer.empty()) answer = {-1};
    return answer;
}