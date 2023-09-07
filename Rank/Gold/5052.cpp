//
// Created by mjk on 2023-07-17.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input,Solve,Output*/
    int t; // 테스트 케이스 수
    cin >> t;
    while (t--) {
        int n; // 전화번호 수
        cin >> n;
        vector<string> data(n);
        for (auto &number: data) {
            cin >> number;
        }
        sort(data.begin(), data.end(), less<>());
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (data[i].length() < data[i + 1].length()) {
                if (data[i] == data[i + 1].substr(0, data[i].length())) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}