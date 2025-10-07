#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g){
    unordered_map<int, list<pair<int,int>>>adj;
    for(int i = 0; i < m; i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;    

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vector<int>key(n+1, INT_MAX);
    vector<bool>mst(n+1, false);
    vector<int>parent(n+1, -1);

    //starting the algorithm:
    key[1] = 0;
    parent[1] = -1;
    
    for(int i = 1; i < n; i++){
        
        int mini = INT_MAX;
        int u;

        //find min wali node: 
        for(int v = 1; v <= n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }

        }

        //mark min node as true:
        mst[u] = true;

        for(auto neighbour: adj[u]){
            int x = neighbour.first;
            int y = neighbour.second;

            if(mst[x] == false && y < key[x]){
                parent[x] = u;
                key[x] = y;
            }
        }

    }

    vector<pair<pair<int, int>, int>> result;
    for(int i = 2; i <= n; i++){
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}
