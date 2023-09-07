//
// Created by mjk on 2023-07-13.
//
#include <iostream>
#include <vector>

using namespace std;

using pii = pair<int, int>;
/*Main*/
int main() {
    /*Input*/
    int n; // 사람 수
    cin >> n;
    vector<pii> data(n); // 사람 데이터
    for (int i = 0; i < n; i++) {
        cin >> data[i].first >> data[i].second;
    }
    /*Solve,Ouput*/
    for (int i = 0; i < n; i++) {
        int rank = 1;
        for (int j = 0; j < n; j++) {
            if (data[i].first < data[j].first && data[i].second < data[j].second) {
                rank++;
            }
        }
        cout << rank << " ";
    }
}