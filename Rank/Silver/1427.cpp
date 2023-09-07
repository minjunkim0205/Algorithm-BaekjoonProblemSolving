//
// Created by mjk on 2023-07-24.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*Main*/
int main() {
    /*Input*/
    string n;
    cin >> n;
    /*Solve*/
    sort(n.begin(), n.end(), greater<>());
    /*Output*/
    cout << n;
    return 0;
}