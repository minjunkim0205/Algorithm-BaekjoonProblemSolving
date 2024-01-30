//
// Created by mjk on 2024-01-30.
//
#include <iostream>

using namespace std;

int main(){
    /*Input*/
    int n; cin >> n;
    /*Solve, Output*/
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= (n-i); ++j) {
            cout << " ";
        }
        for (int j = 1; j <= i; ++j) {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}