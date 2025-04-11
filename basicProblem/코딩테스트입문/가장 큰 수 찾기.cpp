#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array) {
    int max_value = *max_element(array.begin(), array.end());
    int max_index = max_element(array.begin(), array.end()) - array.begin();
    return { max_value, max_index };
}