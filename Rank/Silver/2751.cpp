//
// Created by mjk on 2023-07-14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*Main*/
int main() {
    /*Input*/
    int n; // 숫자 개수
    cin >> n;
    vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    /*Solve*/
    sort(data.begin(), data.end(), less<>());
    /*Output*/
    for (int i = 0; i < n; ++i) {
        cout << data[i] << "\n";
    }
    return 0;
}