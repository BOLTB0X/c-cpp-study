#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer = {n};
    
    while (n > 1) {
        if (n % 2) {
            n = 3 * n + 1;
        }
        else {
            n /= 2;
        }
        answer.push_back(n);
    }
    
    return answer;
}