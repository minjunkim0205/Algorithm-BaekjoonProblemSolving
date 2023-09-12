//
// Created by mjk on 2023-09-12.
//
#include <iostream>
#include <vector>

using namespace std;

/*Const*/
const int INF = 10000000+1; // 100,000 * 100 + 1
/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input*/
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<int>> table(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        table[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        table[a][b] = min(table[a][b], c);
    }
    /*Solve*/
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                table[i][j] = min(table[i][j], table[i][k] + table[k][j]);
            }
        }
    }
    /*Output*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (table[i][j] == INF) {
                cout << "0";
            } else {
                cout << table[i][j];
            }
            cout << " ";
        }
        cout << "\n";
    }
    return 0;
}