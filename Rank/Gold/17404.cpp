//
// Created by mjk on 2023-09-04.
//
#include <iostream>
#include <vector>

using namespace std;
/*Enum*/
/*enum RGB {
    r,
    g,
    b
};*/
/*Struct*/
struct Rgb {
    int r; // Red
    int g; // Green
    int b; // Blue
};

/*Main*/
int main() {
    /*Input*/
    int n;
    cin >> n;
    vector<Rgb> data(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> data[i].r >> data[i].g >> data[i].b;
    }
    /*Solve*/
    Rgb ans = {0, 0, 0};
    vector<Rgb> dp(n + 1, {0, 0, 0});
    dp[1] = {data[1].r, 1000000, 1000000}; // R
    for (int i = 2; i <= n; i++) {
        dp[i].r = data[i].r + min(dp[i - 1].g, dp[i - 1].b);
        dp[i].g = data[i].g + min(dp[i - 1].r, dp[i - 1].b);
        dp[i].b = data[i].b + min(dp[i - 1].r, dp[i - 1].g);
    }
    ans.r = min(dp[n].g, dp[n].b);
    dp[1] = {1000000, data[1].g, 1000000}; // G
    for (int i = 2; i <= n; i++) {
        dp[i].r = data[i].r + min(dp[i - 1].g, dp[i - 1].b);
        dp[i].g = data[i].g + min(dp[i - 1].r, dp[i - 1].b);
        dp[i].b = data[i].b + min(dp[i - 1].r, dp[i - 1].g);
    }
    ans.g = min(dp[n].r, dp[n].b);
    dp[1] = {1000000, 1000000, data[1].b}; // B
    for (int i = 2; i <= n; i++) {
        dp[i].r = data[i].r + min(dp[i - 1].g, dp[i - 1].b);
        dp[i].g = data[i].g + min(dp[i - 1].r, dp[i - 1].b);
        dp[i].b = data[i].b + min(dp[i - 1].r, dp[i - 1].g);
    }
    ans.b = min(dp[n].r, dp[n].g);
    /*Output*/
    cout << min(ans.r, min(ans.g, ans.b));
    return 0;
}