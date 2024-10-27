#include <string>
#include <vector>

using namespace std;

int solution(int n, string control) {
    int answer = n;
    
    for (const char ch: control) {
        if (ch == 'w') answer++;
        else if (ch == 's') answer--;
        else if (ch == 'd') answer += 10;
        else if (ch == 'a') answer -= 10;
    }
    return answer;
}