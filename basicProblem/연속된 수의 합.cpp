#include <string>
#include <vector>

using namespace std;

vector<int> solution(int num, int total) {
    vector<int> answer;
    vector<int> arr;
    
    for (int i = -(num + total); i<= (num + total); i++) {
        arr.push_back(i);
    }
    
    for (int i = 0; i <= arr.size() - num; ++i) {
        vector<int> temp;
        int sum = 0;
        
        for (int j = i; j < i + num; ++j) {
            temp.push_back(arr[j]);
            sum += arr[j];
        }
        
        if (sum == total) {
            answer = temp;
            break;
        }
    }
    return answer;
}