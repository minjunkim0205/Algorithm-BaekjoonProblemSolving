//
// Created by mjk on 2023-07-25.
//
#include <iostream>

using namespace std;

/*Function*/
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result = result * i;
    }
    return result;
}

int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(n - k) * factorial(k));
}

/*Main*/
int main() {
    /*Input*/
    int n, k;
    cin >> n >> k;
    /*Solve,Output*/
    cout << binomialCoefficient(n, k);
    return 0;
}