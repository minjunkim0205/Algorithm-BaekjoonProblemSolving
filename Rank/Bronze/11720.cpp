//
// Created by mjk on 2023-07-08.
//
#include <iostream>

using namespace std;

int main() {
    /*Input*/
    int n;
    cin >> n;
    char s[101];
    cin >> s;
    /*Solve,Output*/
    int number_sum = 0;
    for (char c : s) {
        if(c == '\0') {
            break;
        }
        number_sum += int(c)-int('0');
    }
    cout << number_sum;
    return 0;
}