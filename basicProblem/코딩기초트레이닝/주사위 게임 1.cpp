#include <string>
#include <vector>

using namespace std;

int abs(int a) {
    return a < 0 ? -a : a;
}

int solution(int a, int b) {
    int answer = 0;
    
    if (a % 2 && b % 2)
        answer = a*a + b*b;
    else if (a % 2 || b % 2)
        answer = 2 * (a + b);
    else
        answer = abs(a - b);
    
    return answer;
}