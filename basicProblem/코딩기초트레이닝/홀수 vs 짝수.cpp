#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    int i = 1;
    int even_sum = accumulate(num_list.begin(), num_list.end(), 0, [&i] (int sum, int a) { return !(i++ % 2) ? sum += a : sum; });
    
    i = 1;
    int odd_sum = accumulate(num_list.begin(), num_list.end(), 0, [&i] (int sum, int a) { return i++ % 2 ? sum += a : sum; });
    return even_sum > odd_sum ? even_sum : odd_sum;
}