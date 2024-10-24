#include <string>
#include <vector>

using namespace std;

int get_sevenCount(int n) {
    int res = 0;
    
    while (n) {
        int r = n % 10;
        res += r == 7 ? 1 : 0;
        n /= 10;
    }
    
    return res;
}

int solution(vector<int> array) {
    int answer = 0;
    
    for (const int ele: array) {
        answer += get_sevenCount(ele);
    }
    
    return answer;
}