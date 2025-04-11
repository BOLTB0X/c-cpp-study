#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for (const vector<int> q: queries) {
        int temp = arr[q[0]];
        arr[q[0]] = arr[q[1]];
        arr[q[1]] = temp;
    }
    
    return arr;
}