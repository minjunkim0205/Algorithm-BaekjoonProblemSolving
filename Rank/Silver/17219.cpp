//
// Created by mjk on 2023-07-16.
//
#include <iostream>
#include <map>

using namespace std;

/*main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input*/
    int n, m;
    cin >> n >> m;
    map<string, string> data;
    for (int i = 0; i < n; i++) {
        string site, pass;
        cin >> site >> pass;
        data[site] = pass;
    }
    /*Solve,Output*/
    for (int i = 0; i < m; i++) {
        string site;
        cin >> site;
        cout << data[site] << '\n';
    }
    return 0;
}