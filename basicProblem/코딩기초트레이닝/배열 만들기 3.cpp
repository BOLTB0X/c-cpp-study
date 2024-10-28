#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> intervals) {
    vector<int> answer;
    
    for (const vector<int> interval: intervals) {
        vector<int> temp = vector<int>(arr.begin() + interval[0], arr.begin() + interval[1] + 1);
        answer.insert(answer.end(), temp.begin(), temp.end());
    }
    return answer;
}