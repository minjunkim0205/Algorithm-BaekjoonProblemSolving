//
// Created by mjk on 2023-08-30.
//
#include <iostream>
#include <vector>

using namespace std;

/*Main*/ // dp
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    /*Input*/
    int n;
    cin >> n;
    vector<int> data(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> data[i];
    }
    /*Solve*/
    vector<int> dp(n + 1, 0);
    dp[1] = data[1];
    dp[2] = dp[1] + data[2];
    for (int i = 3; i <= n; i++) {
        dp[i] = max(data[i] + data[i - 1] + dp[i - 3], data[i] + dp[i - 2]);
    }
    /*Output*/
    cout << dp[n];
    return 0;
}