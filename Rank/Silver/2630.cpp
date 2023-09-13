//
// Created by mjk on 2023-09-13.
//
#include <iostream>
#include <vector>

using namespace std;

/*Function*/
bool isWhite(const vector<vector<int>> &grid, const int y, const int x, const int size) {
    bool flag = true;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (grid[i][j] != 0) {
                flag = false;
            }
        }
    }
    return flag;
}

bool isBlue(const vector<vector<int>> &grid, const int y, const int x, const int size) {
    bool flag = true;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (grid[i][j] != 1) {
                flag = false;
            }
        }
    }
    return flag;
}

void solve(const vector<vector<int>> &grid, int &cnt_white, int &cnt_blue, const int y, const int x, const int size) {
    if (isWhite(grid, y, x, size)) {
        cnt_white++;
        return;
    } else if (isBlue(grid, y, x, size)) {
        cnt_blue++;
        return;
    } else {
        int next_size = size / 2;
        solve(grid, cnt_white, cnt_blue, y, x, next_size);
        solve(grid, cnt_white, cnt_blue, y, x + next_size, next_size);
        solve(grid, cnt_white, cnt_blue, y + next_size, x, next_size);
        solve(grid, cnt_white, cnt_blue, y + next_size, x + next_size, next_size);
    }
}

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    /*Input*/
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (auto &row: grid) {
        for (auto &cell: row) {
            cin >> cell;
        }
    }
    /*Solve*/
    int cnt_blue = 0;
    int cnt_white = 0;
    solve(grid, cnt_white, cnt_blue, 0, 0, n);
    /*Output*/
    cout << cnt_white << "\n" << cnt_blue;
    return 0;
}