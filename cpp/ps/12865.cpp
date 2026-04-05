#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int k, vector<int> w, vector<int> v) {
    vector<int> dp(k + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = k; j >= 1; --j) {
            if (w[i] <= j) {
                dp[j] = max(v[i] + dp[j - w[i]], dp[j]);
            }
        }
    }

    // for (int i = 1; i <= k; ++i)
    //     cout << dp[i] << ' ';
    // cout << '\n'; 
    return dp[k];
}

int main(void) {
    int n, k;
    vector<int> w, v;

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        w.push_back(a);
        v.push_back(b);
    }

    cout << solution(n, k, w, v);

    return 0;
}