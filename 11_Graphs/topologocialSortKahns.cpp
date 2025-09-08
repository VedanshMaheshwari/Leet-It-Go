#include <bits/stdc++.h>
using namespace std;

// BFS function for topological sort (Kahn's algorithm)
vector<int> bfsTopoSort(unordered_map<int, list<int>> &adj, vector<int> &indegree, int v) {
    queue<int> q;
    // push all nodes with indegree = 0
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;
    while (!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);
        // reduce indegree of neighbours
        for (auto i : adj[front]) {
            indegree[i]--;
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    return ans;
}

// Wrapper function
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adj;

    // build adjacency list
    for (int i = 0; i < e; i++) {
        int a = edges[i][0];
        int b = edges[i][1];
        adj[a].push_back(b);
    }

    // calculate indegree
    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++) {
        for (auto j : adj[i]) {
            indegree[j]++;
        }
    }

    // call BFS helper
    return bfsTopoSort(adj, indegree, v);
}
