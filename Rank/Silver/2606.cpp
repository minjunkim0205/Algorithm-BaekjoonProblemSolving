//
// Created by mjk on 2023-09-04.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*Struct*/
struct Computer {
    vector<int> linked_computer;
    bool visited = false;
};

/*Main*/
int main() {
    /*FastIO*/
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    /*Input*/
    int n, m;
    cin >> n >> m;
    vector<Computer> network(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        network[a].linked_computer.push_back(b);
        network[b].linked_computer.push_back(a);
    }
    /*Solve*/
    int ans = 0;
    queue<int> computer_queue;
    network[1].visited = true;
    computer_queue.push(1);
    while (!computer_queue.empty()) {
        int cur = computer_queue.front();
        computer_queue.pop();
        for (const auto &nxt: network[cur].linked_computer) {
            if (!network[nxt].visited) {
                ans++;
                network[nxt].visited = true;
                computer_queue.push(nxt);
            }
        }
    }
    /*Output*/
    cout << ans;
    return 0;
}