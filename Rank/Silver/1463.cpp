//
// Created by mjk on 2023-08-29.
//
#include <iostream>
#include <vector>

using namespace std;

/*Main*/
int main() {
    /*Input*/
    int n;
    cin >> n;
    /*Solve*/
    vector<int> dp(n + 1); // dp[0] is not used (1~n, size=n+1)
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0) {
            if ((dp[i / 2] + 1) < dp[i]) {
                dp[i] = (dp[i / 2] + 1);
            }
        }
        if (i % 3 == 0) {
            if ((dp[i / 3] + 1) < dp[i]) {
                dp[i] = (dp[i / 3] + 1);
            }
        }
    }
    /*Output*/
    cout << dp[n];
    return 0;
}
