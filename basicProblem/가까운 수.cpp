#include <string>
#include <vector>

using namespace std;

int abs(int a) {
    return a < 0 ? -a : a;
}

int solution(vector<int> array, int n) {
    int answer = array.front();
    
    for (int i = 1; i < array.size(); ++i) {
        if (abs(answer - n) > abs(array[i] - n)) {
            answer = array[i];
        } else if (abs(answer - n) == abs(array[i] - n)) {
            answer = answer > array[i] ? array[i] : answer;
        }
    }
    
    return answer;
}