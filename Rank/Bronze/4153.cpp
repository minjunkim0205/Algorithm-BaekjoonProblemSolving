//
// Created by mjk on 2023-07-27.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*Function*/
int square(const int n) {
    return n*n;
}
/*Main*/
int main() {
    /*Input,Solve,Output*/
    while(true) {
        vector<int> data(3);
        for (auto &i: data) {
            cin >> i;
        }
        if((data[0]+data[1]+data[2]) == 0) {
            break;
        }
        sort(data.begin(), data.end(), less<>());
        if((square(data[0])+square(data[1])) == square(data[2])) {
            cout << "right\n";
        } else {
            cout << "wrong\n";
        }
    }
    return 0;
}