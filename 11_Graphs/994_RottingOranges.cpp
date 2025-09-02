#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] =  2;
                }
                else{
                    visited[i][j] = 0;
                }
            }
        }

        int totalMins = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            totalMins = max(time, totalMins);
            for(int i = 0; i < 4; i++){
                int newR = row + drow[i];
                int newC = col + dcol[i];
                if(newR>=0  && newR<n && newC>=0 && newC>=0 && newC<m 
                && grid[newR][newC] == 1 && visited[newR][newC] != 2){
                    q.push({{newR,newC}, time+1});
                    visited[newR][newC] = 2;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return totalMins;
    }
};