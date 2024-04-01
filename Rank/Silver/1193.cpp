//
// Created by mjk on 2024-04-01.
//
#include <iostream>
#include <vector>
/*
 * 1 | 2 1 | 3 2 1 | 4 3 2 1 |
 * 1 | 1 2 | 1 2 3 | 1 2 3 5 |
 * 1   2 3   4 5 6   7 8 9 10
 */
using namespace std;
/*Main*/
int main(){
    // Input
    int x; cin >> x; // 1 <= x <= 10,000,000
    // Solve
    int m = 1;
    int cnt = 1;
    while (true){
        if (x > cnt){
            break;
        }
        cnt++;
        m+=cnt;
    }
    // Output
    cout << cnt;
    return 0;
}