//
// Created by mjk on 2023-07-14.
//
#include <iostream>

using namespace std;

/*Function*/
void star(int y, int x, int n) {
    if (n == 1) {
        cout << "*";
    }
    else if (((y/(n/3))%3 == 1) && ((x/(n/3))%3 == 1)) {
        cout << " ";
    }
    else {
        star(y, x, n/3);
    }
}

/*Main*/
int main() {
    /*Input*/
    int n;
    cin >> n;
    /*Solve,Output*/
    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            star(y, x, n);
        }
        cout << "\n";
    }
    return 0;
}