#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:

    void dfs(int node, vector<vector<int>>& isConnected ,unordered_map<int,bool>&visited, int size){
        visited[node] = true;
        for (int j = 0; j < size; j++) {
            if (isConnected[node][j] == 1 && !visited[j]) {
                dfs(j, isConnected, visited, size);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int V = isConnected.size();
        int count = 0;

        unordered_map<int,bool> visited;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                count++;
                dfs(i, isConnected, visited, V);
            }
        }
        return count;
    }
};