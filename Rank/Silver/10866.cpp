//
// Created by mjk on 2023-07-14.
//
#include <iostream>
#include <string>
#include <deque>

using namespace std;

/*Main*/
int main() {
    /*Fast IO*/
    std::cin.tie(nullptr);
    ios::sync_with_stdio(false);
    /*Input,Solve,Output*/
    int n; // 명령줄 수
    cin >> n;
    deque<int> data;
    for (int i = 0; i < n; ++i) {
        string type;
        cin >> type;
        if (type == "push_front") {
            int num;
            cin >> num;
            data.push_front(num);
        } else if (type == "push_back") {
            int num;
            cin >> num;
            data.push_back(num);
        } else if (type == "pop_front") {
            if (data.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << data.front() << "\n";
                data.pop_front();
            }
        } else if (type == "pop_back") {
            if (data.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << data.back() << "\n";
                data.pop_back();
            }
        } else if (type == "size") {
            cout << data.size() << "\n";
        } else if (type == "empty") {
            cout << int(data.empty()) << "\n";
        } else if (type == "front") {
            if (data.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << data.front() << "\n";
            }
        } else if (type == "back") {
            if (data.empty()) {
                cout << "-1" << "\n";
            } else {
                cout << data.back() << "\n";
            }
        }
    }
    return 0;
}