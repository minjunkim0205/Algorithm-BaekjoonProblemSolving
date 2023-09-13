//
// Created by mjk on 2023-09-13.
//
#include <iostream>
#include <vector>

using namespace std;

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input,Solve*/
    int n, m;
    cin >> n >> m;
    vector<int> data(n + 1, 0); // 누적합 기반 데이터 저장 백터
    for (int k = 1; k <= n; k++) {
        int a;
        cin >> a;
        data[k] = data[k - 1] + a;
    }
    /*Output*/
    for (int k = 0; k < m; k++) {
        int i, j;
        cin >> i >> j;
        cout << (data[j] - data[i - 1]) << "\n";
    }
    return 0;
}