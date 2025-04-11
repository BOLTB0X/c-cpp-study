#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    for (int n = i; n <= j; ++n) {
        int temp = n;
        
        while (temp) {
            int r = temp % 10;
            if (r == k) answer++;
            temp /= 10;
        }
    }
    
    return answer;
}