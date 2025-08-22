#include<unordered_map>
#include<queue>
#include<iostream>
#include<vector>
using namespace std;

void bfs(vector<vector<int>> &adj, unordered_map<int,bool>&visited, vector<int>&answer, int node){
    queue<int> q;
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        answer.push_back(frontNode);

        for(auto i : adj[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void bfs(vector<vector<int>> &adj,  vector<int>&ans, unordered_map<int,bool>&visi, int node){

    queue<int>q;
    q.push(node);
    visi[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for(int i = 0; i < adj[frontNode].size(); i++){
            if(!visi[adj[frontNode][i]]){
                q.push(adj[frontNode][i]);
                visi[adj[frontNode][i]] = true;
            }   
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    unordered_map<int,bool>visited;
    vector<int>answer;

    //traverse all the vertex 
    // doing this because of all components
    bfs(adj, visited, answer, 0);
    return answer;
}