//
// Created by mjk on 2023-07-08.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    /*Input*/
    int n;
    cin >> n;
    vector<vector<bool>> room(n, vector<bool>(n, true)); // 빈 공간을 true 로 두고 풀이
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; ++j) {
            if (temp[j] == 'X') {
                room[i][j] = false;
            }
        }
    }
    /*Solve*/
    int count_row_space = 0; // 행(row)자리 확인
    for (int i = 0; i < n; ++i) {
        bool check_row_space = false;
        for (int j = 0; j < n - 1; ++j) {
            if (room[i][j] && room[i][j + 1]) {
                if (!check_row_space) {
                    count_row_space++;
                }
                check_row_space = true;
            } else {
                check_row_space = false;
            }
        }
    }
    int count_col_space = 0; // 열(col)자리 확인
    for (int i = 0; i < n; ++i) {
        bool check_col_space = false;
        for (int j = 0; j < n - 1; ++j) {
            if (room[j][i] && room[j + 1][i]) {
                if (!check_col_space) {
                    count_col_space++;
                }
                check_col_space = true;
            } else {
                check_col_space = false;
            }
        }
    }
    /*Output*/
    cout << count_row_space << ' ' << count_col_space;
    return 0;
}