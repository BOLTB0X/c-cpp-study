#include <string>
#include <vector>

using namespace std;

int solution(string n_str) {
    int answer = 0;
    for (int i = n_str.size()-1, j = 1; i >= 0; --i, j *= 10) {
        answer += (n_str[i] - '0') * j;
    }
    return answer;
}