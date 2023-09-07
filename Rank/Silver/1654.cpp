//
// Created by mjk on 2023-08-31.
//
#include <iostream>
#include <vector>

using namespace std;
/*Using*/
using ll = long long;
/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input*/
    ll k, n;
    cin >> k >> n;
    vector<ll> data(k);
    ll max_data = 0;
    for (auto &i: data) {
        cin >> i;
        max_data = max(max_data, i);
    }
    /*Solve*/
    ll ans = 0;
    ll left = 1;
    ll right = max_data;
    ll mid;
    while (left <= right) {
        mid = (left + right) / 2;
        ll cnt = 0;
        for (const auto &i: data) {
            cnt += ll(i / mid);
        }
        if (cnt >= n) {
            left = mid + 1;
            ans = max(mid, ans);
        } else if (cnt < n) {
            right = mid - 1;
        }
    }
    /*Output*/
    cout << ans;
    return 0;
}