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

/*Function*/
int solve(const vector<vector<Edge>> &graph, const int start, const int end) {
    vector<int> distance(graph.size(), INF);
    distance[start] = 0;
    priority_queue<Edge> edge_queue;
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
    /*Input*/
    int v, e, p;
    cin >> v >> e >> p;
    vector<vector<Edge>> graph(v + 1, vector<Edge>(0));
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    /*Solve*/
    int start_to_stopover = solve(graph, 1, p);
    int stopover_to_end = solve(graph, p, v);
    int start_to_end = solve(graph, 1, v);
    /*Output*/
    if (start_to_stopover + stopover_to_end == start_to_end) {
        cout << "SAVE HIM";
    } else {
        cout << "GOOD BYE";
    }
    return 0;
}