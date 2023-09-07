//
// Created by mjk on 2023-07-12.
//
#include <iostream>
#include <queue>

using namespace std;
/*Main*/
int main() {
    /*Input*/
    int n, k; // 사람 수, 요세푸스 순열 시작점
    cin >> n >> k;
    /*Solve*/
    queue<int> ord;
    queue<int> ans;
    for (int i = 1; i <= n; ++i) {
        ord.push(i);
    }
    while (!ord.empty()) {
        for (int i = 0; i < k-1; ++i) {
            ord.push(ord.front());
            ord.pop();
        }
        ans.push(ord.front());
        ord.pop();
    }
    /*Output*/
    cout << "<";
    while (!ans.empty()) {
        cout << ans.front();
        ans.pop();
        if (!ans.empty()) {
            cout << ", ";
        }
    }
    cout << ">";
    return 0;
}