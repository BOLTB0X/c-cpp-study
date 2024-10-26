#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 1;
    
    for (const char ch: to_string(num)) {
        if (ch == k + '0') {
            break;
        }
        answer++;
    }
    
    return answer > to_string(num).size() ? -1 : answer;
}