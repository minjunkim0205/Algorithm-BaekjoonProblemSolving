//
// Created by mjk on 2023-08-29.
//
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input*/
    int t;
    cin >> t;
    while (t--) {
        string p;
        int n;
        string x;
        cin >> p >> n >> x;
        /*Solve*/
        deque<int> data;
        int cur = -1;
        for (const auto &c: x) {
            if (int('0') <= c && c <= int('9')) {
                cur *= 10;
                cur += (int(c) - int('0'));
            } else {
                if (c == ',' || c == ']') {
                    if (cur > 0) {
                        data.push_back(cur);
                    }
                }
                cur = 0;
            }
        }
        bool flag_error = false;
        bool flag_reverse = false;
        if (data.size() != n) {
            flag_error = true;
        }
        if (!flag_error) {
            for (const auto &c: p) {
                if (c == 'R') {
                    flag_reverse = !flag_reverse;
                } else if (c == 'D') {
                    if (data.empty()) {
                        flag_error = true;
                        break;
                    }
                    if (flag_reverse) {
                        data.pop_back();
                    } else {
                        data.pop_front();
                    }
                }
            }
        }
        if (flag_reverse) {
            reverse(data.begin(), data.end());
        }
        /*Output*/
        if (flag_error) {
            cout << "error\n";
        } else {
            cout << "[";
            for (const auto &i: data) {
                cout << i;
                if (&i != &data.back()) {
                    cout << ",";
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}