//
// Created by mjk on 2023-09-01.
//
#include <iostream>
#include <vector>
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
    int distance = NULL;
    bool visited = false;
};

/*Main*/
int main() {
    /*Input*/
    int n, m;
    cin >> n >> m;
    vector<vector<Cell>> grid(n, vector<Cell>(m));
    Coordinate goal = {};
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int i;
            cin >> i;
            if (i == 0) {
                grid[r][c].info = non;
            } else if (i == 1) {
                grid[r][c].info = road;
                grid[r][c].distance = -1;
            } else if (i == 2) {
                grid[r][c].info = road;
                goal.y = r;
                goal.x = c;
            }
        }
    }
    /*Solve*/
    queue<Coordinate> cell_queue;
    grid[goal.y][goal.x].distance = 0;
    grid[goal.y][goal.x].visited = true;
    cell_queue.push(goal);
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
                    if (!(grid[nxt.y][nxt.x].visited)) {
                        grid[nxt.y][nxt.x].distance = grid[cur.y][cur.x].distance + 1;
                        grid[nxt.y][nxt.x].visited = true;
                        cell_queue.push(nxt);
                    }
                }
            }
        }
    }
    /*Output*/
    for (const auto &row_cells: grid) {
        for (const auto &c: row_cells) {
            cout << c.distance << " ";
        }
        cout << "\n";
    }
    return 0;
}