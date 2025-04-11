#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    
    for (const int ele : array) {
        if (ele == n) answer++;
    }
    return answer;
}