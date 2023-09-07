//
// Created by mjk on 2023-09-01.
//
#include <iostream>

using namespace std;

/*Main*/
int main() {
    /*Input,Solve,Output*/
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            break;
        }
        if (a > b) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}