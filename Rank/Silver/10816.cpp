//
// Created by mjk on 2023-07-25.
//
#include <iostream>
#include <map>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input,Solve,Output*/
    int n;
    cin >> n;
    map<int, int> data;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        data[num]++;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int num;
        cin >> num;
        cout << data[num] << " ";
    }
    return 0;
}