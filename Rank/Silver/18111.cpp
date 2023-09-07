//
// Created by mjk on 2023-08-28.
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
    int n, m, b;
    cin >> n >> m >> b; // (1 ≤ M, N ≤ 500, 0 ≤ B ≤ 6.4 × 10^7)
    vector<int> data(n * m);
    for (auto &i: data) {
        cin >> i;
    }
    /*Solve*/
    int ans_time = 64000000;
    int ans_height = 0;
    for (int h = 0; h <= 256; h++) {
        int cnt_dig = 0;
        int cnt_fill = 0;
        int cur_b = b;
        for (const auto &i: data) {
            if (i > h) {
                cnt_dig += (i - h);
                cur_b += (i - h);
            } else if (i < h) {
                cnt_fill += (h - i);
                cur_b -= (h - i);
            }
        }
        if (cur_b >= 0) {
            if (cnt_dig * 2 + cnt_fill <= ans_time) {
                ans_height = h;
                ans_time = cnt_dig * 2 + cnt_fill;
            }
        }
    }
    /*Output*/
    cout << ans_time << " " << ans_height;
    return 0;
}