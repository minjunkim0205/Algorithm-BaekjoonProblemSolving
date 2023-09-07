//
// Created by mjk on 2023-08-31.
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
    vector<Rgb> dp(n + 1, {0, 0, 0});
    dp[1] = data[1];
    for (int i = 2; i <= n; i++) {
        dp[i].r = data[i].r + min(dp[i - 1].g, dp[i - 1].b);
        dp[i].g = data[i].g + min(dp[i - 1].r, dp[i - 1].b);
        dp[i].b = data[i].b + min(dp[i - 1].r, dp[i - 1].g);
    }
    /*Output*/
    cout << min(dp[n].r, min(dp[n].g, dp[n].b));
    return 0;
}