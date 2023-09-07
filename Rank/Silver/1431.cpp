//
// Created by mjk on 2023-07-23.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*Function*/
int compare(string &a, string &b) {
    if (a.size() != b.size()) {
        return (a.size() < b.size());
    }
    int sum_a = 0;
    int sum_b = 0;
    for (int i = 0; i < a.size(); i++) {
        if ((a[i] >= '0') && (a[i] <= '9')) {
            sum_a += a[i] - '0';
        }
        if ((b[i] >= '0') && (b[i] <= '9')) {
            sum_b += b[i] - '0';
        }
    }
    if (sum_a != sum_b) {
        return (sum_a < sum_b);
    } else {
        return (a < b);
    }
}
/*Main*/
int main() {
    /*Input*/
    int n;
    cin >> n;
    vector<string> data(n);
    for (auto &s: data) {
        cin >> s;
    }
    /*Solve*/
    sort(data.begin(), data.end(), compare);
    /*Output*/
    for (auto &s: data) {
        cout << s << "\n";
    }
    return 0;
}
