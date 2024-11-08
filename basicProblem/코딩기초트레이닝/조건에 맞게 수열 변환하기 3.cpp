#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int k) {
    vector<int> answer;
    if (k % 2) {
        for (const int a: arr)
            answer.push_back(a * k);
    } else {
        for (const int a: arr)
            answer.push_back(a + k);
    }
    return answer;
}