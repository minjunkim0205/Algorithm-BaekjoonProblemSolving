//
// Created by mjk on 2023-07-14.
//
#include <iostream>

using namespace std;
/*Main*/
int main() {
    /*Fast IO*/
    std::cin.tie(nullptr);
    ios::sync_with_stdio(false);
    /*Input*/
    int n; // 펙토리얼
    cin >> n;
    /*Solve*/
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if ((i % (5 * 5 * 5)) == 0) {
            count+=3;
        } else if ((i % (5 * 5)) == 0) {
            count+=2;
        } else if ((i % (5)) == 0) {
            count+=1;
        }
    }
    /*Output*/
    cout << count;
    return 0;
}