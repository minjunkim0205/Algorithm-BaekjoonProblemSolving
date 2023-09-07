//
// Created by mjk on 2023-07-09.
//
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;
/*Enum*/
enum Circuit {
    non,
    redstone_dust,
    redstone_block,
    redstone_lamp
};
/*Struct*/
struct Coordinate {
    int y;
    int x;
};

/*Function*/
Circuit checkCircuit(vector<vector<Circuit>> &circuit_diagram, Coordinate &nxt) {
    if ((nxt.y < 0 || circuit_diagram.size() <= nxt.y) || (nxt.x < 0 || circuit_diagram[0].size() <= nxt.x)) {
        return Circuit::non;
    }
    return circuit_diagram[nxt.y][nxt.x];
}

void bfs(vector<vector<Circuit>> &circuit_diagram, vector<vector<int>> &electrical_signal_diagram,
         queue<Coordinate> &electrical_signal_queue) {
    while (!electrical_signal_queue.empty()) {
        Coordinate cur = electrical_signal_queue.front();
        electrical_signal_queue.pop();

        int dy[4] = {1, 0, -1, 0};
        int dx[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; ++i) {
            Coordinate nxt = {cur.y + dy[i], cur.x + dx[i]};
            if (checkCircuit(circuit_diagram, nxt) == Circuit::redstone_dust) {
                if (electrical_signal_diagram[nxt.y][nxt.x] < electrical_signal_diagram[cur.y][cur.x] - 1) {
                    electrical_signal_diagram[nxt.y][nxt.x] = electrical_signal_diagram[cur.y][cur.x] - 1;
                    electrical_signal_queue.push(nxt);
                }
            } else if (checkCircuit(circuit_diagram, nxt) == Circuit::redstone_lamp) {
                if (electrical_signal_diagram[nxt.y][nxt.x] < electrical_signal_diagram[cur.y][cur.x] - 1) {
                    electrical_signal_diagram[nxt.y][nxt.x] = electrical_signal_diagram[cur.y][cur.x] - 1;
                }
            }
        }
    }
}

/*Main*/
int main() {
    /*Input*/
    int h, w, n; // 세로, 가로, 회로 갯수
    cin >> w >> h >> n;
    vector<vector<Circuit>> circuit_diagram(h, vector<Circuit>(w, Circuit::non)); // 회로도
    vector<vector<int>> electrical_signal_diagram(h, vector<int>(w, 0)); // 전기신호도
    queue<Coordinate> electrical_signal_queue; // 전기신호도 큐
    for (int i = 0; i < n; ++i) {
        string b; // 회로 타입
        int y, x; // 회로y, 회로x
        cin >> b >> x >> y;
        if (b == "redstone_dust") {
            circuit_diagram[y][x] = Circuit::redstone_dust;
        } else if (b == "redstone_block") {
            circuit_diagram[y][x] = Circuit::redstone_block;
            electrical_signal_diagram[y][x] = 16;
            electrical_signal_queue.push({y, x});
        } else if (b == "redstone_lamp") {
            circuit_diagram[y][x] = Circuit::redstone_lamp;
        }
    }
    /*Solve*/
    bfs(circuit_diagram, electrical_signal_diagram, electrical_signal_queue);
    bool off_lamp_flag = false;
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (circuit_diagram[y][x] == Circuit::redstone_lamp) {
                if (electrical_signal_diagram[y][x] == 0) {
                    off_lamp_flag = true;
                    break;
                }
            }
        }
        if (off_lamp_flag) {
            break;
        }
    }
    /*Output*/
    if (off_lamp_flag) {
        cout << "failed";
    } else {
        cout << "success";
    }
    return 0;
}