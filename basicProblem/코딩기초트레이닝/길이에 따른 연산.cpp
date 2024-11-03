#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    int sum = accumulate(num_list.begin(), num_list.end(), 0);
    int product = accumulate(num_list.begin(), num_list.end(), 1, [] (int a, int b) { 
        return a *= b;
        });
    return num_list.size() >= 11 ? sum : product;
}