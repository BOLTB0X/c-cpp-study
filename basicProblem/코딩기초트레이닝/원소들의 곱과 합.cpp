#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int sum1 = 0, sum2 = 1;
    
    for (const int num: num_list) {
        sum1 += (num);
        sum2 *= num;
    }
    return sum1 * sum1 > sum2;
}