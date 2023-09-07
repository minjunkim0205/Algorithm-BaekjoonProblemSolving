//
// Created by mjk on 2023-07-08.
//
#include <iostream>

using namespace std;

int main(){
    /*Input,Solve,Output*/
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int r;
        char s[21];
        cin >> r >> s;
        for (char c : s){
            if (c == '\0'){
                break;
            }
            for (int j = 0; j < r; ++j) {
                cout << c;
            }
        }
        cout << "\n";
    }
    return 0;
}