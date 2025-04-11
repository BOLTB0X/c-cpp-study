#include <string>
#include <vector>

using namespace std;

int solution(int chicken) {
    int answer = 0;
    
    while (chicken >= 10) {
        int d = chicken / 10;
        answer += d;
        chicken %= 10;
        chicken += d;
    }
    
    return answer;
}