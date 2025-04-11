#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer = {0, 0};
    
    for (const int num: num_list) {
        if (num % 2) {
            answer[1] += 1;
        } else {
            answer[0] += 1;
        }
    }
    return answer;
}