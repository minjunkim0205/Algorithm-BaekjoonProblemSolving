//
// Created by mjk on 2023-09-13.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*Function*/
void solve(vector<vector<int>> &grid, ){

}
/*Main*/
int main() {
    /*Input*/
    int n, r, c;
    cin >> n >> r >> c;
    n = int(pow(2, n));
    vector<vector<int>> grid(n, vector<int> (n));
    /*Solve*/
    solve();
    /*Output*/
    cout << grid[r][c];
    return 0;
}