//
// Created by mjk on 2023-07-08.
//
#include <iostream>
#include <map>

using namespace std;

int main() {
    /*Input,Solve*/
    int n, m;
    cin >> n >> m;
    map<int, bool> check_number;
    for (int i = 0; i < (n + m); i++) {
        int temp;
        cin >> temp;
        if (check_number[temp]) {
            check_number.erase(temp);
        } else {
            check_number[temp] = true;
        }
    }
    /*Output*/
    cout << check_number.size();
    return 0;
}