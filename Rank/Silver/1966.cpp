//
// Created by mjk on 2024-01-11.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*Struct*/
struct document {
    int number;
    int priority;
};

/*Main*/
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        queue<document> queue;
        priority_queue<int, vector<int>, less<>> priority_queue;
        for (int i = 0; i < n; ++i) {
            int priority;
            cin >> priority;
            queue.push(document{i, priority});
            priority_queue.push(priority);
        }
        int ans = 0;
        while (!queue.empty()) {
            document trg = queue.front();
            queue.pop();
            if (priority_queue.top() == trg.priority) {
                priority_queue.pop();
                ans++;
                if (trg.number == m) {
                    cout << ans << "\n";
                }
            } else {
                queue.push(trg);
            }
        }
    }
    return 0;
}