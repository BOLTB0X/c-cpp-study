#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    for (const char ch: my_string) {
        if (ch >= '1' && ch <= '9')
            answer += ch - '0';
    }
    return answer;
}