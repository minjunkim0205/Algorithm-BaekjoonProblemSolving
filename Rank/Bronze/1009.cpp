//
// Created by mjk on 2023-12-24.
//
#include <iostream>

using namespace std;

int main(){
    /*Input,Solve,Output*/
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        int a, b; cin >> a >> b;
        int result = a%10;
        for(int j = 0; j < b-1; ++j) {
            result = (result * a)%10;
        }
        if(result == 0){
            result = 10;
        }
        cout << result << "\n";
    }
    return 0;
}