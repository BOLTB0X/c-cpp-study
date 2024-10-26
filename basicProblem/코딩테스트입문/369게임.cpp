#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    
    for (const char ch: to_string(order)) {
        if (ch == '3' || ch == '6' || ch == '9')
            answer++;
    }
    
    return answer;
}