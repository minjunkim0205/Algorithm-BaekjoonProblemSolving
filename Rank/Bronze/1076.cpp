//
// Created by mjk on 2023-07-09.
//
#include <iostream>
#include <string>

using namespace std;

/*Main*/
int main() {
    /*Input*/
    string color[10] = {"black", "brown", "red",
                        "orange", "yellow", "green",
                        "blue", "violet", "grey",
                        "white"};
    string t;
    int mem[3];
    long long r = 0;
    /*Solve*/
    for (int i = 0; i < 3; ++i) {
        cin >> t;
        for (int j = 0; j < 10; ++j) {
            if (color[j] == t) mem[i] = j;
        }
    }
    r = mem[0] * 10 + mem[1];
    for (int i = 0; i < mem[2]; ++i) r *= 10;
    /*Output*/
    cout << r;
    return 0;
}