//
// Created by mjk on 2023-09-14.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Const value*/
const int MAX = 100000;// 100,000
/*Main*/
int main() {
    /*Input*/
    int n, k;
    cin >> n >> k;
    /*Solve*/
    vector<int> data(MAX+1, MAX);
    queue<int> queue;
    data[n] = 0;
    queue.push(n);
    while (!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        if (cur == k) {
            break;
        }
        int next[3] = {cur-1, cur+1, cur*2};
        for (const auto &nxt: next) {
            if (0 <= nxt && nxt <= MAX) {
                if (data[nxt] > data[cur] + 1) {
                    data[nxt] = data[cur] + 1;
                    queue.push(nxt);
                }
            }
        }
    }
    /*Output*/
    cout << data[k];
    return 0;
}