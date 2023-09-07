//
// Created by mjk on 2023-08-30.
//
#include <iostream>
#include <queue>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input,Solve,Output*/
    int n;
    cin >> n;
    priority_queue<int, vector<int>, less<>> data;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (!data.empty()) {
                cout << data.top() << "\n";
                data.pop();
            } else {
                cout << "0\n";
            }
        } else {
            data.push(x);
        }
    }
    return 0;
}