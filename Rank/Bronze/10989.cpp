//
// Created by mjk on 2023-07-14.
//
#include <iostream>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input,Solve*/
    int n;
    cin >> n;
    int data[10001] = {0,};
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        data[num]++;
    }
    /*Ouputs*/
    for (int i = 1; i < 10001; i++) {
        for (int j = 0; j < data[i]; j++) {
            cout << i << '\n';
        }
    }
    return 0;
}