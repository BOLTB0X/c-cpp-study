#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 0;
    int check[101][101];
    int dx[8] = { -1, 1, 0, 0, -1, 1, -1, 1};
    int dy[8] = {0, 0, -1, 1, -1, 1, 1, -1};
    
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (board[i][j] == 0) continue;
            
            check[i][j] = 1;
            for (int d = 0; d < 8; ++d) {
                int nx = i + dx[d];
                int ny = j + dy[d];
                
                if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[i].size()) continue;
                
                if (board[nx][ny] || check[nx][ny] == 1) continue;
                
                check[nx][ny] = 1;
            }
            
        }
    }
    
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            if (!check[i][j]) answer++;
        }
    }
    
    return answer;
}