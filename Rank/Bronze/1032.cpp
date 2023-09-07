//
// Created by mjk on 2023-07-10.
//
#include<iostream>
#include<string>

using namespace std;

int main() {
    /*Input*/
    int n;
    cin >> n;
    string str[50];
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    /*Solve,Output*/
    char c;
    for (int i = 0; i < str[0].length(); i++) {
        c = str[0][i];
        for (int j = 0; j < n; j++) {
            if (c != str[j][i]) {
                c = '?';
                break;
            }
        }
        cout << c;
    }
}