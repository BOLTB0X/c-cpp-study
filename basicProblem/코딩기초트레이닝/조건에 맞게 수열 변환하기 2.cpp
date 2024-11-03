#include <string>
#include <vector>

using namespace std;

vector<int> work(vector<int> arr) {
    vector<int> res(arr);
    
    for (int &r: res) {
        if (r >= 50 && !(r % 2))
            r /= 2;
        else if (r < 50 && r % 2) {
            r *= 2;
            r++;
        }
    }
    
    return res;
}

int solution(vector<int> arr) {
    int answer = 0;
    vector<int> ret = work(arr);
    
    while (arr != ret) {
        arr = ret;
        ret = work(arr);
        answer++;
    }
    
    return answer;
}