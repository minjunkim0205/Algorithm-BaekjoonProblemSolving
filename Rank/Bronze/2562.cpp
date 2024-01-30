//
// Created by mjk on 2024-01-30.
//
#include <iostream>

using namespace std;
/*Const*/
const int NUMBER_OF_DATA = 9;
/*Struct*/
struct element{
    int number;
    int index;
};
/*Main*/
int main(){
    /*Input, Solve*/
    element ans = {-1, 0};
    for (int i = 1; i <= NUMBER_OF_DATA; ++i) {
        int temp; cin >> temp;
        if(temp > ans.number){
            ans.number = temp;
            ans.index = i;
        }
    }
    /*Output*/
    cout << ans.number << "\n" << ans.index;
    return 0;
}