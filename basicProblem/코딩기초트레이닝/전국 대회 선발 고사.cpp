#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0, cnt = 0, value = 10000;
    map<int,int> dict;
    vector<int> sorted_rank = rank;
    sort(sorted_rank.begin(), sorted_rank.end());
    
    for (int i = 0; i < rank.size(); ++i)
        dict[rank[i]] = i;
    
    for (int i = 0; i < rank.size(); ++i) {
        if (cnt == 3) {
            break;
        }
        
        if (attendance[dict[sorted_rank[i]]]) {
            answer += (value*dict[sorted_rank[i]]);
            cnt++;
            value /= 100;
        }
    }
    return answer;
}