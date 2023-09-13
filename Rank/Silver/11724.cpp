//
// Created by mjk on 2023-09-13.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Struct*/
struct Node {
    vector<int> edges;
    bool visited = false;
};

/*Function*/
void solve(vector<Node> &graph, const int start) { // Bfs
    queue<int> node_queue;
    node_queue.push(start);
    while (!node_queue.empty()) {
        int cur = node_queue.front();
        node_queue.pop();
        for (const auto &nxt: graph[cur].edges) {
            if (!graph[nxt].visited) {
                graph[nxt].visited = true;
                node_queue.push(nxt);
            }
        }
    }
}

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    /*Input*/
    int n, m;
    cin >> n >> m;
    vector<Node> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].edges.push_back(v);
        graph[v].edges.push_back(u);
    }
    /*Solve*/
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!graph[i].visited) {
            solve(graph, i);
            cnt++;
        }
    }
    /*Output*/
    cout << cnt;
    return 0;
}