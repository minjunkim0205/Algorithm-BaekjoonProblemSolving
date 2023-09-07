//
// Created by mjk on 2023-07-12.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Function*/
void coutArray(vector<pair<int, int>> &data, int size) {
    for (int i = 0; i < size; ++i) {
        cout << data[i].first << " " << data[i].second;
        if (i == size - 1) {
            break;
        }
        cout << "\n";
    }
}

/*Main*/
int main() {
    /*Input*/
    int n; // 점의 개수
    cin >> n;
    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i].first >> data[i].second;
    }
    /*Solve*/
    sort(data.begin(), data.end(), less<>());
    /*Output*/
    coutArray(data, n);
    return 0;
}