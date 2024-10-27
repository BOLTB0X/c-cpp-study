#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    int idx = 0;
    
    while (idx < arr.size()) {
        if (stk.empty() || stk.back() < arr[idx]) {
            stk.push_back(arr[idx]);
            idx++;
        }
        else {
            stk.pop_back();
        }
    }
    return stk;
}