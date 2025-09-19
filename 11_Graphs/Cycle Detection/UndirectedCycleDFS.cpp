#include <unordered_map>
#include <list>
#include <queue>
#include <vector>
#include <string>
using namespace std;


bool dfsCycle(unordered_map<int, list<int>>&adj,int node,unordered_map<int, bool>&visi){
    unordered_map<int,int>parent;
    parent[node] = -1;
    visi[node] = true;

    for(auto i: adj[node]){
        if(visi[i] && i != parent[i]){
            return true;    
        }else{
            dfsCycle(adj, i ,visi);
        }

    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visi;

    for(int i = 0; i < m; i++){
        int v = edges[i][0];
        int u = edges[i][1];

        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    for(int i = 0; i < n; i++){
        if(!visi[i]){
            bool ans = dfsCycle(adj, i, visi);
        }
    }

    
}
