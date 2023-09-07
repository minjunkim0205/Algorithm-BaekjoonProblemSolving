//
// Created by mjk on 2023-08-04.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Function*/
bool binarySearch(const vector<int> &data, const int trg) {
    int low = 0;
    int high = int(data.size()) - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (trg == data[mid]) {
            return true;
        } else if (trg < data[mid]) {
            high = mid - 1;
        } else if (trg > data[mid]) {
            low = mid + 1;
        }
    }
    return false;
}

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input*/
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i: a) {
        cin >> i;
    }
    /*Solve,Output*/
    sort(a.begin(), a.end(), less<>());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        cout << int(binarySearch(a, temp)) << "\n";
    }
    return 0;
}