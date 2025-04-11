#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    if (arr1.size() != arr2.size()) {
        if (arr1.size() > arr2.size())
            return 1;
        else
            return -1;
    }
    
    int arr1_sum = accumulate(arr1.begin(), arr1.end(), 0);
    int arr2_sum = accumulate(arr2.begin(), arr2.end(), 0);
    
    if (arr1_sum > arr2_sum)
        return 1;
    
    else if (arr1_sum < arr2_sum)
        return -1;
    
    return 0;
}