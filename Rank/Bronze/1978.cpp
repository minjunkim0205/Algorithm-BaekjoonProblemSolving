//
// Created by mjk on 2023-07-28.
//
#include <iostream>

using namespace std;
/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input,Solve*/
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        int cnt = 0;
        for (int j = 1; j <= temp; j++) {
            if ((temp % j) == 0){
                cnt++;
            }
        }
        if (cnt == 2) {
            ans++;
        }
    }
    /*Output*/
    cout << ans;
}