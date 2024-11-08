#include <string>
#include <vector>

using namespace std;

int abs(int a) {
    return a < 0 ? -a : a;
}

vector<vector<int>> solution(vector<vector<int>> arr) {
    vector<vector<int>> answer = arr;
    int row = arr.size(), col = arr[0].size();
    int cnt = row > col ? row : col;
    
    for (int i = 0; i < cnt; ++i) {
        if (i < row) {
            for (int j = 0; j < abs(cnt-col); ++j)
                answer[i].push_back(0);
        }
        else {
            vector<int> temp(cnt, 0);
            answer.push_back(temp);
        }
    }
    return answer;
}