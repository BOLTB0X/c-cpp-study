#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 0; i < n; ++i) {
        answer++;
        while (to_string(answer).find('3') != string::npos || answer % 3 == 0) {
            answer++;
        }
    }
    
    return answer;
}