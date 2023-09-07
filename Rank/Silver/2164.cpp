//
// Created by mjk on 2023-08-06.
//
#include <iostream>
#include <queue>

using namespace std;

/*Main*/
int main() {
    /*Input*/
    int n;
    cin >> n;
    queue<int> data;
    for (int i = 0; i < n; i++) {
        data.push(i+1);
    }
    /*Solve*/
    while(data.size() > 1) {
        data.pop();
        data.push(data.front());
        data.pop();
    }
    /*Output*/
    cout << data.front();
    return 0;
}