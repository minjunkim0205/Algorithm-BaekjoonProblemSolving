//
// Created by mjk on 2023-07-22.
//
#include <iostream>

using namespace std;

/*Main*/
int main() {
    /*Input*/
    int n;
    cin >> n;
    /*Solve*/
    int dp[46] = {};
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 0; i < n-1; i++) {
        dp[i+2] = dp[i+1] + dp[i];
    }
    /*Output*/
    cout << dp[n];
}