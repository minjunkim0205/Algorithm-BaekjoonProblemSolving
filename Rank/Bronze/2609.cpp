//
// Created by mjk on 2023-07-30.
//
#include<iostream>

using namespace std;

/*Function*/
int gcd(int a, int b) {
    int r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

int lcm(int a, int b) {
    return ((a*b)/gcd(a, b));
}

/*Main*/
int main() {
    /*Input*/
    int a, b;
    cin >> a >> b;
    /*Solve,Output*/
    cout << gcd(a, b) << "\n" << lcm(a, b);
    return 0;
}