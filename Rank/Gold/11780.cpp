//
// Created by mjk on 2023-09-12.
//
#include <iostream>
#include <vector>

using namespace std;

/*Const*/
const int INF = 10000000; // 100,000 * 100
/*Struct*/
struct Cell {
    int distance;
    int next;
};

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
    vector<vector<Cell>> table(n + 1, vector<Cell>(n + 1, {INF, -1}));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < table[a][b].distance) {
            table[a][b].distance = c;
            table[a][b].next = b;
        }
    }
    /*Solve*/
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    if ((table[i][k].distance + table[k][j].distance) < table[i][j].distance) {
                        table[i][j].distance = table[i][k].distance + table[k][j].distance;
                        table[i][j].next = table[i][k].next;
                    }
                }
            }
        }
    }
    /*Output*/
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (table[i][j].distance == INF) {
                cout << "0";
            } else {
                cout << table[i][j].distance;
            }
            cout << " ";
        }
        cout << "\n";
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (table[i][j].distance == INF) {
                cout << "0";
            } else {
                vector<int> route;
                route.push_back(i);
                while (route.back() != j) {
                    int cur = route.back();
                    route.push_back(table[cur][j].next);
                }
                cout << route.size() << " ";
                for (const auto &cell: route) {
                    cout << cell << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}