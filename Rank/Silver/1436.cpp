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
    int n;
    cin >> n;
    /*Solve*/
    int count = 0;
    int ans = 665;
    while (count < n) {
        ans++;
        int temp = ans;
        while (temp >= 666) {
            if ((temp % 1000) == 666) {
                count++;
                break;
            }
            temp = temp / 10;
        }
    }
    /*Output*/
    cout << ans;
    return 0;
}