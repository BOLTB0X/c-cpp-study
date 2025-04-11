#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) {
    int answer = 0, maxFreq = -1;
    unordered_map<int, int> umap;
    
    for (int ele: array) {
        umap[ele]++;
    }
    
    for (const auto &m: umap) {
        if (m.second > maxFreq) {
            maxFreq = m.second;
            answer = m.first;
        } else if (m.second == maxFreq) {
            answer = -1;
        }
    }
    
    return answer;
}