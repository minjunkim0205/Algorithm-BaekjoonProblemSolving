//
// Created by mjk on 2023-08-28.
//
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input*/
    int n, m;
    cin >> n >> m;
    /*Solve*/
    unordered_map<string, int> data_psi;
    unordered_map<int, string> data_pis;
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        data_psi[name] = i;
        data_pis[i] = name;
    }
    /*Output*/
    for (int i = 0; i < m; i++) {
        string trg;
        cin >> trg;
        int trg_to_i = atoi(trg.c_str());
        if (trg_to_i == 0) {
            cout << data_psi[trg] << "\n";
        } else {
            cout << data_pis[trg_to_i] << "\n";
        }
    }
    return 0;
}