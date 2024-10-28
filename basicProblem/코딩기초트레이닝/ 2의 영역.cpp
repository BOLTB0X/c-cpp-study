#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if (find(arr.begin(), arr.end(), 2) == arr.end()) return {-1};

    vector<int> ra(arr);
    reverse(ra.begin(), ra.end());

    auto it1 = find(arr.begin(), arr.end(), 2);
    auto it2 = find(ra.begin(), ra.end(), 2);
    
    int i = distance(arr.begin(), it1);
    int j = distance(ra.begin(), it2);

    return vector<int>(arr.begin() + i, arr.begin() + arr.size() - j);
}