//
// Created by mjk on 2023-07-24.
//
#include<iostream>

using namespace std;
/*Main*/
int main() {
    /*Input,Solve*/
    int n;
    cin >> n;
    int a[100][100] = {0,};
    int ans = 0;
    for (int k = 0; k < n; k++) {
        int y, x;
        cin >> x >> y;
        for (int i = y; i < (y + 10); i++) {
            for (int j = x; j < (x + 10); j++) {
                if (a[i][j] == 0) {
                    ans++;
                    a[i][j] = 1;
                }
            }
        }
    }
    /*Output*/
    cout << ans;
    return 0;
}
