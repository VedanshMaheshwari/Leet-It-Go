#include <bits/stdc++.h>
using namespace std;

void topoSort(vector<int>& answer, vector<int>& inDegree, unordered_map<int, list<int>>& adj, int v) {
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        answer.push_back(front);

        for (auto i : adj[front]) {
            inDegree[i]--;
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
    }
}

vector<int> topologicalSort(vector<pair<int, int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < e; i++) {
        int a = edges[i].first - 1;
        int b = edges[i].second - 1;

        adj[a].push_back(b);
    }

    vector<int> inDegree(v);
    for (int i = 0; i < v; i++) {
        for (auto j : adj[i]) {
            inDegree[j]++;
        }
    }

    vector<int> answer;
    topoSort(answer, inDegree, adj, v);
    return answer;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    vector<int> topoSortAnswer = topologicalSort(edges, n, edges.size());

    // If topological sort does not include all nodes, a cycle exists
    if (topoSortAnswer.size() == n) return false;  // no cycle
    return true;  // cycle exists
}
