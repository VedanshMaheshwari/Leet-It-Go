#include <unordered_map>
#include <bits/stdc++.h> 
#include <list>
#include <stack>
using namespace std;

void topoSort(int node, unordered_map<int,bool>&visi, stack<int>&st, unordered_map<int, list<int>>&adj){
    visi[node] = true;

    for(auto i: adj[node]){
        if(!visi[i]){
            topoSort(i, visi, st, adj);
        }
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    unordered_map<int, list<int>>adj;
    for(int i = 0; i < e; i++){
        int a = edges[i][0];
        int b = edges[i][1];

        adj[a].push_back(b);
    }  

    unordered_map<int,bool> visi;
    stack<int> st;
    for(int i = 0; i < v; i++){
        if(!visi[i]){
            topoSort(i, visi, st, adj);
        }
    }

    vector<int> answer;
    while(!st.empty()){
        answer.push_back(st.top());
        st.pop();
    }
    return answer;
    
}