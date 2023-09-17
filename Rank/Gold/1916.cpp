//
// Created by mjk on 2023-09-11.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*Const value*/
const int INF = 100000000 + 1; // 100,000 * 1,000 + 1
/*Struct*/
struct Edge {
    int node;
    int weight;

    bool operator<(const Edge &_edge) const {
        return weight > _edge.weight;
    }
};

/*Function*/
int solve(const vector<vector<Edge>> &graph, const int &start, const int &end) {
    vector<int> distance(graph.size(), INF);
    distance[start] = 0;
    priority_queue<Edge> edge_queue;
    edge_queue.push({start, distance[start]});
    while (!edge_queue.empty()) {
        Edge cur = edge_queue.top();
        edge_queue.pop();
        if(distance[cur.node] >= cur.weight) {
            for (const auto &nxt: graph[cur.node]) {
                if (distance[nxt.node] > distance[cur.node] + nxt.weight) {
                    distance[nxt.node] = distance[cur.node] + nxt.weight;
                    edge_queue.push({nxt.node, distance[nxt.node]});
                }
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
    std::cout.tie(nullptr);
    /*Input*/
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<Edge>> graph(n + 1, vector<Edge>());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    int start, end;
    cin >> start >> end;
    /*Solve*/
    int ans = solve(graph, start, end);
    /*Output*/
    cout << ans;
    return 0;
}