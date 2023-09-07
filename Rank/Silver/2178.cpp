//
// Created by mjk on 2023-08-30.
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
/*Enum*/
enum Info {
    non,
    road
};

/*Struct*/
struct Coordinate {
    int y;
    int x;

    Coordinate operator+(const Coordinate &coordinate) const {
        return {y + coordinate.y, x + coordinate.x};
    }
};

struct Cell {
    Info info = non;
    int cell_count = NULL;
    int visited = false;
};
/*Function*/
/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    /*Input*/
    int n, m;
    cin >> n >> m;
    vector<vector<Cell>> grid(n, vector<Cell>(m));
    for (int r = 0; r < n; r++) {
        string row_cells;
        cin >> row_cells;
        for (int c = 0; c < m; c++) {
            if (row_cells[c] == '1') {
                grid[r][c].info = road;
            }
        }
    }
    /*Solve*/
    queue<Coordinate> cell_queue;
    grid[0][0].cell_count = 1;
    grid[0][0].visited = true;
    cell_queue.push({0, 0});

    while (!cell_queue.empty()) {
        Coordinate cur = cell_queue.front();
        cell_queue.pop();
        Coordinate dir[4] = {{0,  1},
                             {-1, 0},
                             {0,  -1},
                             {1,  0}};
        for (const auto &d: dir) {
            Coordinate nxt = cur + d;
            if ((0 <= nxt.y && nxt.y < n) && (0 <= nxt.x && nxt.x < m)) {
                if (grid[nxt.y][nxt.x].info == road) {
                    if (!grid[nxt.y][nxt.x].visited) {
                        grid[nxt.y][nxt.x].cell_count = grid[cur.y][cur.x].cell_count + 1;
                        grid[nxt.y][nxt.x].visited = true;
                        cell_queue.push(nxt);
                    }
                }
            }
        }
    }
    /*Output*/
    cout << grid[n - 1][m - 1].cell_count;
    return 0;
}