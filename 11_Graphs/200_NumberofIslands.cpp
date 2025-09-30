#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:

    void bfs(vector<vector<char>>& grid, int row, int col, vector<vector<int>>&visited){
        visited[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        
        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && grid[nr][nc] == '1' && visited[nr][nc] == 0){
                    q.push({nr,nc});
                    visited[nr][nc] = 1;
                }
            }

        }
        
    }

    int numIslands(vector<vector<char>>& grid){
        int answer = 0;

        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    bfs(grid, i, j, visited);
                    islands++;
                }
            }
        }

        return islands;
    }
};