//
// Created by mjk on 2023-09-10.
//
#include <iostream>
#include <string>

using namespace std;

/*Main*/
int main() {
    /*Input*/
    string me, dt;
    cin >> me >> dt;
    /*Solve,Output*/
    if (me.size() >= dt.size()) {
        cout << "go";
    } else {
        cout << "no";
    }
    return 0;
}