//
// Created by mjk on 2023-09-13.
//
#include <iostream>
#include <cmath>

using namespace std;

/*Function*/
void solve(int &ans, const int &r, const int &c, const int size) {
    if(size <= 1){
        return;
    }
    int next_size = size / 2;
    if (r < next_size && c < next_size) {
        ans += int(pow(next_size, 2))*0;
        solve(ans, r, c, next_size);
    } else if (r < next_size && c >= next_size) {
        ans += int(pow(next_size, 2))*1;
        solve(ans, r, (c-next_size), next_size);
    } else if (r >= next_size && c < next_size) {
        ans += int(pow(next_size, 2))*2;
        solve(ans, (r- next_size), c, next_size);
    } else if (r >= next_size && c >= next_size) {
        ans += int(pow(next_size, 2))*3;
        solve(ans, (r - next_size), (c - next_size), next_size);
    }
}

/*Main*/
int main() {
    /*Input*/
    int n, r, c;
    cin >> n >> r >> c;
    /*Solve*/
    n = int(pow(2, n));
    int ans = 0;
    solve(ans, r, c, n);
    /*Output*/
    cout << ans;
    return 0;
}