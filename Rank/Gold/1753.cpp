//
// Created by mjk on 2023-09-05.
//
#include <iostream>
#include <queue>

using namespace std;

/*Const value*/
const int INF = 300000 * 10;
/*Struct*/
struct Edge {
    int node;
    int weight;

    bool operator<(const Edge &_edge) const {
        return weight > _edge.weight;
    }
};

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*Input*/
    int v, e;
    cin >> v >> e;
    vector<vector<Edge>> graph(v + 1, vector<Edge>(0));
    int k;
    cin >> k;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    /*Solve*/
    vector<int> distance(v + 1, INF);
    distance[k] = 0;
    priority_queue<Edge> edge_queue;
    edge_queue.push({k, distance[k]});
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
    /*Output*/
    for (int i = 1; i <= v; i++) {
        if (distance[i] == INF) {
            cout << "INF\n";
        } else {
            cout << distance[i] << "\n";
        }
    }
    return 0;
}