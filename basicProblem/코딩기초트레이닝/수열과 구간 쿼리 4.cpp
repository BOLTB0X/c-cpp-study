#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer = arr;
    
    for (const vector<int> q: queries) {
        for (int i = q[0]; i <= q[1]; ++i) {
            if (!(i% q[2])) {
                answer[i]++;
            }
        }
    }
    return answer;
}