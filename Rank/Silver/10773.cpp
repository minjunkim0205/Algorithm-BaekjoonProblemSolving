//
// Created by mjk on 2024-04-01.
//
#include <iostream>
#include <stack>

using namespace std;
/*Main*/
int main(){
    // Input, Solve
    int k; cin >> k; // 1 <= k <= 100,000
    stack<int> data;
    while (k--){
        int temp; cin >> temp;
        if (temp != 0){
            data.push(temp);
        }else{
            if(!data.empty()){
                data.pop();
            }
        }
    }
    // Output
    int ans = 0;
    while(!data.empty()){
        ans += data.top();
        data.pop();
    }
    cout << ans;
    return 0;
}