//
// Created by mjk on 2023-09-05.
//
#include <iostream>
#include <queue>

using namespace std;

/*Const value*/
const int INF = 10000 * 1000; // 10^4*10^3
/*Struct*/
struct Edge {
    int node;
    int weight;

    bool operator<(const Edge &_edge) const {
        return weight > _edge.weight;
    }
};

/*Function*/
int solve(vector<vector<Edge>> &graph, const int start, const int end) {
    // Raw graph
    vector<vector<int>> prev(graph.size());
    vector<int> distance(graph.size(), INF);
    distance[start] = 0;
    priority_queue<Edge> edge_queue;
    edge_queue.push({start, distance[start]});
    while (!edge_queue.empty()) {
        Edge cur = edge_queue.top();
        edge_queue.pop();
        for (const auto &nxt: graph[cur.node]) {
            if (distance[nxt.node] > distance[cur.node] + nxt.weight) {
                prev[nxt.node].clear();
                prev[nxt.node].push_back(cur.node);
                distance[nxt.node] = distance[cur.node] + nxt.weight;
                edge_queue.push({nxt.node, distance[nxt.node]});
            } else if (distance[nxt.node] == distance[cur.node] + nxt.weight) {
                prev[nxt.node].push_back(cur.node);
            }
        }
    }
    // Remove( prev edge
    vector<int> visited(graph.size(), 0);
    queue<int> edge_remove_queue;
    visited[end] = 1;
    edge_remove_queue.push(end);
    while (!edge_remove_queue.empty()) {
        int cur = edge_remove_queue.front();
        edge_remove_queue.pop();
        for (const auto nxt: prev[cur]) {
            if (visited[nxt] <= graph[nxt].size()) {
                for (auto &trg: graph[nxt]) {
                    if (trg.node == cur) {
                        trg.node = nxt;
                    }
                }
                visited[nxt]++;
                edge_remove_queue.push(nxt);
            }
        }
    }
    // New graph
    distance.clear();
    distance = vector<int>(graph.size(), INF);
    distance[start] = 0;
    edge_queue.push({start, distance[start]});
    while (!edge_queue.empty()) {
        Edge cur = edge_queue.top();
        edge_queue.pop();
        for (const auto &nxt: graph[cur.node]) {
            if (distance[nxt.node] > distance[cur.node] + nxt.weight) {
                distance[nxt.node] = distance[cur.node] + nxt.weight;
                edge_queue.push({nxt.node, distance[nxt.node]});
            }
        }
    }
    return distance[end];
}

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    while (true) {
        /*Input*/
        int n, m;
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        int s, d;
        cin >> s >> d;
        vector<vector<Edge>> graph(n, vector<Edge>(0));
        for (int i = 0; i < m; i++) {
            int u, v, p;
            cin >> u >> v >> p;
            graph[u].push_back({v, p});
        }
        /*Solve*/
        int ans = solve(graph, s, d);
        /*Output*/
        if (ans == INF) {
            cout << "-1\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}