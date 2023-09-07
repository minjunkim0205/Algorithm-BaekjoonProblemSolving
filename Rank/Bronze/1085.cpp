//
// Created by mjk on 2023-08-28.
//
#include <iostream>

using namespace std;

/*Main*/
int main() {
    /*Input*/
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    /*Solve*/
    int ans = min(min(x, y), min(w - x, h - y));
    /*Output*/
    cout << ans;
    return 0;
}