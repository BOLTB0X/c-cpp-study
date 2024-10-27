#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    for (const vector<int> q: queries) {
        int temp = 1000001;
        for (int i = q[0]; i <= q[1]; ++i) {
            if (arr[i] > q[2])
                temp = temp < arr[i] ? temp : arr[i];
        }
        answer.push_back(temp == 1000001 ? -1 : temp);
    }
    return answer;
}