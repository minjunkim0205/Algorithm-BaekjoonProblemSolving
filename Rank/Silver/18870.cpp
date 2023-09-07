//
// Created by mjk on 2023-08-31.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input*/
    int n;
    cin >> n;
    vector<int> data(n);
    for (auto &i: data) {
        cin >> i;
    }
    /*Solve*/
    vector<int> copy_data(data);
    sort(copy_data.begin(), copy_data.end(), less<>());
    copy_data.erase(unique(copy_data.begin(), copy_data.end()), copy_data.end());
    /*Output*/
    for (const auto &i: data) {
        // To use the binary search-based lower_bound() function, you need to sort the data you use.
        cout << (lower_bound(copy_data.begin(), copy_data.end(), i) - copy_data.begin()) << " ";
    }
    return 0;
}