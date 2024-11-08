#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    
    for (int i = 0; i < flag.size(); ++i) {
        if (flag[i]) {
            vector<int> temp(arr[i] * 2, arr[i]);
            answer.insert(answer.end(), temp.begin(), temp.end());
        } else {
            for (int j = 0; j < arr[i]; ++j)
                answer.pop_back();
        }
    }
    return answer;
}