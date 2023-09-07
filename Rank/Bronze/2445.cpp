//
// Created by mjk on 2023-08-28.
//
#include <iostream>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    /*Input*/
    int n;
    cin >> n;
    /*Solve,Output*/
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        for (int j = 0; j < 2 * (n - i - 1); j++) {
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            cout << "*";
        }
        for (int j = 0; j < 2 * (i + 1); j++) {
            cout << " ";
        }
        for (int j = 0; j < n - i - 1; j++) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}