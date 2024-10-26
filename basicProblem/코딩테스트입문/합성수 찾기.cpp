#include <string>
#include <vector>

using namespace std;

bool is_composite(int n) {
    vector<int> res;
    
    for (int i = 1; i <= n; ++i)
        if (!(n % i)) res.push_back(i);
    
    return res.size() >= 3;
}

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i <= n; ++i) {
        if (is_composite(i)) answer++;
    }
    
    return answer;
}