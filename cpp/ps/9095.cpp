#include <iostream>
#include <vector>
// 1 = 1 = 1
// 2 = 1 + 1, 2 = 2
// 3 = 1 + 1 + 1, 2 + 1, 1 + 2, 3 = 4
// 4 = 1 + 1 + 1 + 1, 1 + 1 + 2, 1 + 2 + 1, 2 + 1 + 1, 1 + 3, 3 + 1, 4

using namespace std;

int main(void) {
    int n, T;
    vector<int> dp(12, 0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (unsigned int i = 4; i <= 11; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cin >> T;
    while (T) {
        cin >> n;
        cout << dp[n] << '\n';

        T--;
    }

    return 0;
}