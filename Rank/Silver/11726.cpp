//
// Created by mjk on 2023-08-30.
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
    vector<long> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    /*Output*/
    cout << dp[n];
    return 0;
}