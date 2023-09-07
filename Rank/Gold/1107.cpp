//
// Created by mjk on 2023-08-29.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*Struct*/
struct Cell {
    int warp_cell = 0;
    int move_count = 0;
    bool visited = false;
};

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    /*Input*/
    int n, m;
    cin >> n >> m;
    vector<Cell> board(100 + 1);
    for (int i = 0; i < n + m; i++) {
        int u, v;
        cin >> u >> v;
        board[u].warp_cell = v;
    }
    /*Solve*/
    queue<int> cell_queue;
    board[1].move_count = 0;
    board[1].visited = true;
    cell_queue.push(1);
    while (!cell_queue.empty()) {
        int cur = cell_queue.front();
        cell_queue.pop();
        for (int i = 1; i <= 6; i++) {
            int nxt = cur + i;
            if (nxt <= 100) {
                if (board[nxt].warp_cell > 0) {
                    nxt = board[nxt].warp_cell;
                }
                if (!board[nxt].visited) {
                    board[nxt].move_count = board[cur].move_count + 1;
                    board[nxt].visited = true;
                    cell_queue.push(nxt);
                }
            }
        }
    }
    /*Output*/
    cout << board[100].move_count;
    return 0;
}