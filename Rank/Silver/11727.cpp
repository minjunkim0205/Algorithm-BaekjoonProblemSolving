//
// Created by mjk on 2023-09-29.
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
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 3;
    for (int i = 3; i <= n; i++) {
        dp[i] = ((dp[i-2]+dp[i-2]+dp[i-1]) % 10007);
    }
    /*Output*/
    cout << dp[n];
    return 0;
}