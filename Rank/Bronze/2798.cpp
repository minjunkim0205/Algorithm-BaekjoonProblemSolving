//
// Created by mjk on 2023-07-30.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    /*Input*/
    int n, m;
    cin >> n >> m;
    vector<int> data(n);
    for (auto &i: data) {
        cin >> i;
    }
    /*Solve*/
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                int sum = data[i]+data[j]+data[k];
                if (sum <= m) {
                    ans.push_back(sum);
                }
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<>());
    /*Output*/
    cout << ans[0];
    return 0;
}