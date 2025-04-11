#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    int s = 0, e = arr.size() - 1;
    
    for(int i = 0; i < query.size(); i++) {
        if(i % 2 == 0) e = s + query[i];
        else s += query[i];
    }
    
    if (s > e || e >= arr.size()) return {-1};
    
    return vector<int>(arr.begin() + s, arr.begin() + e + 1);
}