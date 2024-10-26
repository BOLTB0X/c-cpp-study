#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> lines) {
    int answer = 0;
    int pos[202];
    
    for (int i = 0; i < 202; ++i) 
        pos[i] = 0;
    
    for (const vector<int> line: lines) {
        for (int i = line[0]; i < line[1]; ++i)
            pos[i+100] += 1;
    }
    
    for (int i = 0; i < 202; ++i) {
        if (pos[i] >= 2) answer++;
    }
    
    return answer;
}