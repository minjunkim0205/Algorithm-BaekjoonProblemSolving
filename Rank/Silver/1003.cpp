//
// Created by mjk on 2023-08-28.
//
#include <iostream>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input,Solve,Output*/
    int fibonacci[41] = {0, 1};
    for (int j = 2; j < 41; j++) {
        fibonacci[j] = fibonacci[j - 1] + fibonacci[j - 2];
    }
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n == 0) {
            cout << "1 0\n";
        } else if (n == 1) {
            cout << "0 1\n";
        } else {
            cout << fibonacci[n - 1] << " " << fibonacci[n] << "\n";
        }
    }
    return 0;
}