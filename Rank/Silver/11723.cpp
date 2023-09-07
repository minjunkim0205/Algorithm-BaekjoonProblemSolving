//
// Created by mjk on 2023-07-16.
//
#include <iostream>
#include <string>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input,Solve,Output*/
    int m; // 연산의 수
    cin >> m;
    int s[21] = {0,};
    for (int i = 0; i < m; ++i) {
        string type;
        int num;
        cin >> type;
        if (type == "add") {
            cin >> num;
            s[num] = 1;
        } else if (type == "remove") {
            cin >> num;
            s[num] = 0;
        } else if (type == "check") {
            cin >> num;
            cout << s[num] << "\n";
        } else if (type == "toggle") {
            cin >> num;
            if (s[num] == 0) {
                s[num] = 1;
            } else {
                s[num] = 0;
            }
        } else if (type == "all") {
            for (auto &n: s) {
                n = 1;
            }
        } else if (type == "empty") {
            for (auto &n: s) {
                n = 0;
            }
        }
    }
    return 0;
}