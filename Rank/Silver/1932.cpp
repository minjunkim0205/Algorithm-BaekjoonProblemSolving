//
// Created by mjk on 2023-09-05.
//
#include <iostream>
#include <vector>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input*/
    int n;
    cin >> n;
    vector<vector<int>> triangle(1 + n + 1, vector<int>(1 + n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    /*Solve*/
    vector<vector<int>> dp(1 + n + 1, vector<int>(1 + n + 1, 0));
    dp[1][1] = triangle[1][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }
    int ans = 0;
    for (const auto &i: dp[n]) {
        ans = max(ans, i);
    }
    /*Output*/
    cout << ans;
    return 0;
}