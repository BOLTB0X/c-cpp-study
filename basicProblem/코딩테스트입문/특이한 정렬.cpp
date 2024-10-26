#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    sort(numlist.begin(), numlist.end(), [n](int a, int b) {
        if (abs(n-a) == abs(n-b))
            return a > b;
        return abs(n-a) < abs(n-b);
    });
        
    return numlist;
}