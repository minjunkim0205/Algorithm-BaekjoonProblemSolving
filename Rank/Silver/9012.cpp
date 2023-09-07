//
// Created by mjk on 2023-08-06.
//
#include <iostream>
#include <string>
#include <stack>

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
    /*Solve,Output*/
    while (t--) {
        string s;
        cin >> s;
        stack<char> data;
        for (const auto &c: s) {
            if (data.empty()) {
                data.push(c);
            } else {
                if (data.top() == '(') {
                    if (c == '(') {
                        data.push(c);
                    } else if (c == ')') {
                        data.pop();
                    }
                } else if (data.top() == ')') {
                    break;
                }
            }
        }
        if (data.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}