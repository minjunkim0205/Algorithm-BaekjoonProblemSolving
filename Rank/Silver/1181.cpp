//
// Created by mjk on 2023-07-14.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*Function*/
bool compare(const string &a, const string &b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}
/*Main*/
int main() {
    /*Fast IO*/
    std::cin.tie(nullptr);
    ios::sync_with_stdio(false);
    /*Input*/
    int n; // 단어 갯수
    cin >> n;
    vector<string> data(n); // 단어들
    for (auto &s : data) {
        cin >> s;
    }
    /*Solve*/
    sort(data.begin(), data.end(), compare);
    data.erase(unique(data.begin(), data.end()), data.end());
    /*Output*/
    for (auto &s : data) {
        cout << s << "\n";
    }
    return 0;
}