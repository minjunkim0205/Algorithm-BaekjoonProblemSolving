//
// Created by mjk on 2023-07-11.
//
#include <iostream>

using namespace std;
/*Main*/
int main() {
    /*Input,Solve,Output*/
    int a[3];
    while (true) {
        cin >> a[0] >> a[1] >> a[2];
        if (!a[0] && !a[1] && !a[2])
            break;
        if (a[1] - a[0] == a[2] - a[1] && a[1] - a[0] != 0)
            cout << "AP " << a[1] - a[0] + a[2] << '\n';
        else
            cout << "GP " << a[1] / a[0] * a[2] << '\n';
    }
    return 0;
}
