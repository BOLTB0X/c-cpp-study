#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    string answer = my_string;
    
    for (const vector<int> q: queries) {
        string temp = answer.substr(q[0], q[1] - q[0]+ 1);
        reverse(temp.begin(), temp.end());
        int idx = 0;
        for (int i = q[0]; i <= q[1]; ++i) {
            answer[i] = temp[idx];
            idx++;
        }
    }
    return answer;
}