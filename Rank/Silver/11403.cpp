//
// Created by mjk on 2023-09-13.
//
#include <iostream>
#include <vector>

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
    vector<vector<int>> table(n, vector<int>(n));
    for (auto &row: table) {
        for (auto &cell: row) {
            cin >> cell;
        }
    }
    /*Solve*/
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (table[i][k] != 0 && table[k][j] != 0) {
                    table[i][j] = 1;
                }
            }
        }
    }
    /*Output*/
    for (const auto &row: table) {
        for (const auto &cell: row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
    return 0;
}