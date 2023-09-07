//
// Created by mjk on 2023-08-07.
//
#include <iostream>

using namespace std;

/*Main*/
int main() {
    /*Input*/
    int n;
    cin >> n;
    /*Solve*/
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    /*Output*/
    cout << ans;
    return 0;
}