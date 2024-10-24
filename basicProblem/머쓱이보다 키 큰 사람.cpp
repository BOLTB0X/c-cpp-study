#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array, int height) {
    int answer = 0;
    
    for (const int ele : array) {
        if (ele > height) answer++;
    }
    return answer;
}