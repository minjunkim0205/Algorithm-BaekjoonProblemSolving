//
// Created by mjk on 2023-07-25.
//
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    while (true) {
        /*Input*/
        string data;
        cin >> data;
        if (data == "0") {
            break;
        }
        /*Solve*/
        string temp = data;
        reverse(temp.begin(), temp.end());
        /*Output*/
        if (data == temp) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}