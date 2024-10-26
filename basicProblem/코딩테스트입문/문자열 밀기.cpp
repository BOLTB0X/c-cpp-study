#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    int size = A.size();
    
    while (answer <= size) {       
        if (A == B) break;
        char las = A.back();
        A.pop_back();
        A = las + A;
        answer++;
    }
    
    return answer > size ? -1 : answer;
}