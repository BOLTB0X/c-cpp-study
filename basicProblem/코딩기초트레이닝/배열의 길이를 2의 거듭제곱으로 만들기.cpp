#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    auto is_power = [](int a) {
        while (a > 1) {
            if (a % 2) return false;
            a /= 2;
        }
        return true;
    };
    
    while (!is_power(answer.size())) {
        answer.push_back(0);
    }
    
    return answer;
}