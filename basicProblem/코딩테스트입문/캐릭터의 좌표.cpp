#include <string>
#include <vector>

using namespace std;

bool in_range(int x, int y, int n, int m) {
    return x >= -n && x <= n && y >= -m && y <= m;
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer = {0, 0};
    int n = board[0] / 2, m = board[1] / 2;
    
    for (const string k : keyinput) {
        if (k == "up") {
            int ny = answer[1] + 1;
            if (in_range(answer[0], ny, n, m)) answer[1] = ny;
        }
        
        else if (k == "down") {
            int ny = answer[1] - 1;
            if (in_range(answer[0], ny, n, m)) answer[1] = ny;
        }
        
        else if (k == "left") {
            int nx = answer[0] - 1;
            if (in_range(nx, answer[1], n, m)) answer[0] = nx;
        }
        
        else {
            int nx = answer[0] + 1;
            if (in_range(nx, answer[1], n, m)) answer[0] = nx;
        }
    }
    return answer;
}