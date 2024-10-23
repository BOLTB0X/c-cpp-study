#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int answer = 0;
    
    for (const int skil: {5, 3, 1}) {
        answer += (hp / skil);
        hp %= skil;
    }
    
    return answer;
}