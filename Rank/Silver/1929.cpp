//
// Created by mjk on 2024-04-01.
//
#include <iostream>
#include <vector>
/* 
 * [ 소수 판별법 ]
 * - 에라토스테네스의 체 
 */
using namespace std;
/*Main*/
int main(){
    // Input
    int m, n; cin >> m >> n; // 1 <= M <= N <= 1,000,000
    // Solve
    bool flag[1000000] = {false, };
    for (int i = 2; i <= n; ++i) { // 일단 1~n 까지
        if ()
    }
    // Ouput
    for (int i = 1; i <= n; ++i) {
        if (!flag[i]){
            cout << i << '\n';
        }
    }
    return 0;
}