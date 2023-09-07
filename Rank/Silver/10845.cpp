//
// Created by mjk on 2023-07-14.
//
#include <iostream>
#include <string>
#include <queue>

using namespace std;

/*Main*/
int main() {
    /*Fast IO*/
    std::cin.tie(nullptr);
    ios::sync_with_stdio(false);
    /*Input,Solve,Output*/
    int n; // 명령줄 수
    cin >> n;
    queue<int> data;
    for (int i = 0; i < n; ++i) {
        string type;
        cin >> type;
        if (type == "push") {
            int num;
            cin >> num;
            data.push(num);
        } else if (type == "pop") {
            if (data.empty()) {
                cout << "-1\n";
            } else {
                cout << data.front() << "\n";
                data.pop();
            }
        } else if (type == "size") {
            cout << data.size() << "\n";
        } else if (type == "empty") {
            cout << int(data.empty()) << "\n";
        } else if (type == "front") {
            if (data.empty()) {
                cout << "-1\n";
            } else {
                cout << data.front() << "\n";
            }
        } else if (type == "back") {
            if (data.empty()) {
                cout << "-1\n";
            } else {
                cout << data.back() << "\n";
            }
        }
    }
    return 0;
}