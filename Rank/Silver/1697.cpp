//
// Created by mjk on 2023-09-14.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Const value*/
const int MAX = 100000;// 100,000
/*Main*/
int main() {
    /*Input*/
    int n, k;
    cin >> n >> k;
    /*Solve*/
    vector<int> data(MAX, -1);
    queue<int> queue;
    data[n] = 0;
    queue.push(n);
    while(!queue.empty()) {
        int cur = queue.front();
        queue.pop();
        if (cur == k) {
            break;
        }
        if(0 <= cur && cur <= MAX){
            if(cur < k){
                int nxt = cur+1;
                if (data[cur]) {

                }
                data[cur+1] = data[cur] + 1;
                queue.push(cur+1);
                data[cur*2] = data[cur] * 2;
                queue.push(cur*2);
            } else if (cur > k) {
                data[cur-1] = data[cur] + 1;
                queue.push(cur-1);
            }
        }
    }
    /*Output*/
    
    return 0;
}
/* [숨바꼭질]
 * 솔루션 : Bfs (1차원)
 * 순간이동 하면 지금 위치에서 x2
 * 일반 이동 하면 지금 위치에서 +1 or -1
 * */