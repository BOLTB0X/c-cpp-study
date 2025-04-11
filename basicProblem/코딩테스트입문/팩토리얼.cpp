#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1, factorial = 1;
    
    while (factorial <= n) {
        factorial *= answer;
        
        if (factorial >= n) break;
        answer++;
    }
    return factorial == n ? answer : answer - 1;
}