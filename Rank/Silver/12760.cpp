//
// Created by mjk on 2023-07-07.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    /*Input*/
    int n, m; // N은 플레이어 수, M는 카드 수(경기 횟수)
    cin >> n >> m;
    vector<vector<int>> player_card_data(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> player_card_data[i][j];
        }
        sort(player_card_data[i].begin(), player_card_data[i].end(), greater<>());
    }
    /*Solve*/
    vector<int> player_win_count(n, 0);
    for (int i = 0; i < m; i++) {
        int check_high_card_number = 0; // 카드 최소 값이1(무조건 루프에서 첫번째 수가 최소 카드로 설정 됌)
        for (int j = 0; j < n; j++) {
            if (check_high_card_number < player_card_data[j][i]) {
                check_high_card_number = player_card_data[j][i];
            }
        }
        for (int j = 0; j < n; j++) {
            if (check_high_card_number == player_card_data[j][i]) {
                player_win_count[j]++;
            }
        }
    }
    /*Output*/
    int check_high_score_player_number = 0; // 카드 최소 값이1(무조건 루프에서 첫번째 수가 최소 카드로 설정 됌)
    for (int i = 0; i < n; i++) {
        if (check_high_score_player_number < player_win_count[i]) {
            check_high_score_player_number = player_win_count[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (check_high_score_player_number == player_win_count[i]) {
            cout << (i + 1) << " ";
        }
    }
    return 0;
}
