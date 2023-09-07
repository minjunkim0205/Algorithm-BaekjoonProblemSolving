//
// Created by mjk on 2023-09-05.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    /*Input*/
    int n, k;
    cin >> n >> k;
    vector<int> p(n + 1, 0);
    vector<int> t(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    /*Solve*/
    vector<int> add_power(n + 1);
    queue<int> speech;
    for (int i = 0; i < k; i++) {
        speech.push(0);
    }
    int effective_shout = 0;
    int shout = 0;
    for (int i = 1; i <= n; i++) {
        add_power[i] = add_power[i - 1] - effective_shout;
        p[i] += add_power[i];
        int count = 0;
        if (t[i] > p[i]) {
            if ((t[i] - p[i]) % k == 0) {
                count = (t[i] - p[i]) / k + 0;
            } else {
                count = (t[i] - p[i]) / k + 1;
            }
        }
        shout += count;
        effective_shout += count;
        speech.push(count);
        add_power[i] += (count * k);
        p[i] += (count * k);
        effective_shout -= speech.front();
        speech.pop();
    }
    /*Output*/
    cout << shout;
    return 0;
}