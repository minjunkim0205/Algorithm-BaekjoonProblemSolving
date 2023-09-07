//
// Created by mjk on 2023-07-25.
//
#include <iostream>
#include <vector>

using namespace std;

/*Main*/
int main() {
    /*Input,Solve*/
    int n;
    cin >> n;
    vector<int> data(n);
    int max = 0;
    for (auto &i: data) {
        cin >> i;
        if (i > max) {
            max = i;
        }
    }
    float sum = 0;
    for (auto &i: data) {
        sum += float(i) / float(max) * 100;
    }
    /*Output*/
    cout << sum / float(n);
    return 0;
}