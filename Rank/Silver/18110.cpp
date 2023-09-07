//
// Created by mjk on 2023-07-14.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
/*Main*/
int main() {
    /*Fast IO*/
    std::cin.tie(nullptr);
    ios::sync_with_stdio(false);
    /*Input*/
    int n; // 난의도 의견수
    cin >> n;
    vector<int> data(n);
    for (auto &i : data) {
        cin >> i;
    }
    /*Solve*/
    sort(data.begin(), data.end(), less<>());
    float ers_per = round(float(n)*15.0f/100.0f);
    data.erase(data.begin(), data.begin()+int(ers_per));
    data.erase(data.end()-int(ers_per), data.end());
    int sum = 0;
    for (auto &i : data) {
        sum+=i;
    }
    /*Output*/
    if (n == 0) {
        cout << 0;
    }
    else {
        cout << round(float(sum)/float(data.size()));
    }
    return 0;
}