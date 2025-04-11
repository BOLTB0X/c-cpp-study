#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr, int idx) {
    
    for (int i = 0; i < arr.size(); ++i) {
        if (i >= idx && arr[i]) return i;
    }
    return -1;
}