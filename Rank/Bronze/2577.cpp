//
// Created by mjk on 2024-01-30.
//
#include <iostream>

using namespace std;

int main(){
    /*Input*/
    int a, b, c;
    cin >> a >> b >> c;
    int trg = a*b*c;
    /*Solve*/
    int ans[10] = {0, };
    while(trg!=0){
        ans[trg%10]++;
        trg=trg/10;
    }
    /*Output*/
    for (auto e : ans) {
        cout << e << "\n";
    }
    return 0;
}