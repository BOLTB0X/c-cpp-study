#include <string>
#include <vector>

using namespace std;

bool is_possible(int n) {
    while (n) {
        int r = n % 10;
        
        if (r != 0 && r != 5) return false;
        n /= 10;
    }
    
    return true;
}

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for (int i = l; i <= r; ++i) {
        if (is_possible(i)) answer.push_back(i);
    }
    
    if (answer.empty()) answer.push_back(-1);
    
    return answer;
}