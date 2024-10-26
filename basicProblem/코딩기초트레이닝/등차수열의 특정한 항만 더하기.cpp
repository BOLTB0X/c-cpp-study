#include <string>
#include <vector>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    vector<int> seq;
    
    seq.push_back(a);
    
    for (int i = 0; i < included.size(); ++i) {
        seq.push_back(seq.back() + d);
    }
    
    for (int i = 0; i < included.size(); ++i) {
        if (included[i]) answer += seq[i];
    }
    return answer;
}