//
// Created by mjk on 2023-09-07.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Const*/
const int INF = 156250; // 125*125*10
/*Struct*/
struct Coordinate {
    int y;
    int x;
    int weight;

    bool operator<(const Coordinate &_coordinate) const {
        return weight > _coordinate.weight;
    }
};

struct Cell {
    int weight; // rupee
};

/*Function*/
int solve(const vector<vector<Cell>> &grid, const Coordinate &start, const Coordinate &end) {
    vector<vector<int>> distance(grid.size(), vector<int>(grid[0].size(), INF));
    distance[start.y][start.x] = grid[start.y][start.x].weight;
    priority_queue<Coordinate> cell_queue;
    cell_queue.push({start.x, start.x, distance[start.y][start.x]});
    while (!cell_queue.empty()) {
        Coordinate cur = cell_queue.top();
        cell_queue.pop();
        const Coordinate dir[4] = {{1,  0},
                                   {0,  1},
                                   {-1, 0},
                                   {0,  -1}};
        for (const auto &d: dir) {
            Coordinate nxt = {(cur.y + d.y), (cur.x + d.x)};
            if ((0 <= nxt.y && nxt.y < grid.size()) && (0 <= nxt.x && nxt.x < grid.size())) {
                if (distance[nxt.y][nxt.x] > distance[cur.y][cur.x] + grid[nxt.y][nxt.x].weight) {
                    distance[nxt.y][nxt.x] = distance[cur.y][cur.x] + grid[nxt.y][nxt.x].weight;
                    cell_queue.push({nxt.y, nxt.x, distance[nxt.y][nxt.x]});
                }
            }
        }
    }
    return distance[end.y][end.x];
}

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int cnt = 1;
    while (true) {
        /*Input*/
        int n;
        cin >> n;
        if (n == 0) {
            break;
        }
        vector<vector<Cell>> grid(n, vector<Cell>(n));
        for (auto &row_cells: grid) {
            for (auto &cell: row_cells) {
                cin >> cell.weight;
            }
        }
        /*Solve*/
        int ans = solve(grid, {0, 0}, {n - 1, n - 1});
        /*Output*/
        cout << "Problem " << cnt << ": " << ans << "\n";
        cnt++;
    }
    return 0;
}