//
// Created by mjk on 2023-07-25.
//
#include <iostream>
#include <vector>

using namespace std;

/*Function*/
int BWBoard(const vector<vector<char>> &data, const int y, const int x){
    const char bw_board[8][8] = {{'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'}};
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (data[i+y][j+x] != bw_board[i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}
int WBBoard(const vector<vector<char>> &data, const int y, const int x){
    const char wb_board[8][8] = {{'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
                                 {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
                                 {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}};
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (data[i+y][j+x] != wb_board[i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input*/
    int n, m;
    cin >> n >> m;
    vector<vector<char>> data(n, vector<char> (m));
    for (auto &s: data) {
        for (auto &c: s) {
            cin >> c;
        }
    }
    /*Solve*/
    int ans = 8*8;
    for (int y = 0; y <= n-8; y++) {
        for (int x = 0; x <= m-8; x++) {
            int temp = min(BWBoard(data, y, x), WBBoard(data, y, x));
            if (temp < ans) {
                ans = temp;
            }
        }
    }
    /*Output*/
    cout << ans;
    return 0;
}