#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

struct Info {
    int x, y, dist, wall;
};

int BFS(const vector<vector<int>>& board, vector<vector<vector<bool>>>& visited, int n, int m) {
    queue<Info> q;
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        Info current = q.front();
        q.pop();

        if (current.x == n - 1 && current.y == m - 1) {
            return current.dist + 1;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if (board[nx][ny] == 0 && !visited[nx][ny][current.wall]) {
                visited[nx][ny][current.wall] = true;
                q.push({nx, ny, current.dist + 1, current.wall});
            } else if (board[nx][ny] == 1 && !current.wall && !visited[nx][ny][current.wall]) {
                visited[nx][ny][1] = true;
                q.push({nx, ny, current.dist + 1, 1});
            }
        }
    }

    return -1;
}

int main() {
    int n, m;
    vector<vector<int>> board;
    vector<vector<vector<bool>>> visited; 

    cin >> n >> m;
    board = vector<vector<int>>(n, vector<int>(m, 0));
    visited = vector<vector<vector<bool>>>(n, vector<vector<bool>>(m, vector<bool>(2, false)));

    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; ++j) {
            board[i][j] = temp[j] - '0';
        }
    }

    cout << BFS(board, visited, n, m) << endl;

    return 0;
}