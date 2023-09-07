//
// Created by mjk on 2023-09-04.
//
#include <iostream>
#include <vector>

using namespace std;

/*Main*/
int main() {
    /*
        dp[1] = 1 : 1
        dp[2] = 2 : 1+1, 2
        dp[3] = 4 : 1+1+1, 1+2, 2+1, 3
        dp[4] = 7 : 1+1+1+1, 1+1+2, 1+3, 2+2
        dp[5] = ? : 1+1+1+1+1, 1+1+1+2, 1+1+3, 1+2+2, 2+2+1, 2+1+1+1, ...
        ...
        dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
    */
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input,Solve,Output*/
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        cout << dp[n] << "\n";
    }
    return 0;
}