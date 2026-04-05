#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> types, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (const int& t: types) {
        for (int i = t; i <= target; ++i) {
            dp[i] += dp[i - t];
        }
    }

    return dp[target];
}

int main(void) {
    int t;

    cin >> t;

    while (t)
    {
        int n, target;
        cin >> n;
        vector<int> types(n);
        for (int i = 0; i < n; ++i) cin >> types[i];
        cin >> target;
        cout << solution(n, types, target) << '\n';
        t--;
    }
    
    return 0;
}