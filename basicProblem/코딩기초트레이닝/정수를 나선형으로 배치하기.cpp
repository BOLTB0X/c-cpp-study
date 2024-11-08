#include <string>
#include <vector>

using namespace std;

bool in_range(int n, int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
    int number = 1, cx = 0, cy = 0, cd = 0;
    
    for (int i = 0; i < n * n; ++i) {
        answer[cx][cy] = number++;
        
        int nx = cx + dx[cd];
        int ny = cy + dy[cd];
        
        if (!in_range(n, nx, ny) || answer[nx][ny]) {
            cd = (cd + 1) % 4;
            nx = cx + dx[cd];
            ny = cy + dy[cd];
        }
        
        cx = nx;
        cy = ny;
    }
    
    return answer;
}