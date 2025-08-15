#include<iostream>
#include<vector>
using namespace std;


class Solution {

private:
    bool isSafe(vector<vector<int>>& maze, vector<vector<int>> &visited, int x, int y, int n){
        if((x >= 0 && x < n) && (y >= 0 && y < n) && (visited[x][y] == 0) && (maze[x][y] == 1)){
            return true;
        }else{
            return false;
        }
    }

    void solve(vector<vector<int>>& maze, int n,vector<string>& ans, vector<vector<int>> &visited,  string path, int x, int y){
        //Base 
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        
        //DOWN
        int newx = x + 1;
        int newy = y;
        if(isSafe(maze, visited, newx, newy, n)){
            path.push_back('D');
            solve(maze, n, ans, visited, path, newx, newy);
            path.pop_back();
        }

        //LEFT
        newx = x;
        newy = y-1;
        if(isSafe(maze, visited, newx, newy, n)){
            path.push_back('L');
            solve(maze, n, ans, visited, path, newx, newy);
            path.pop_back();
        }
        
        //RIGHt
        newx = x;
        newy = y+1;
        if(isSafe(maze, visited, newx, newy, n)){
            path.push_back('R');
            solve(maze, n, ans, visited, path, newx, newy);
            path.pop_back();
        }
        
        //UP
        newx = x-1;
        newy = y;
        if(isSafe(maze, visited, newx, newy, n)){
            path.push_back('U');
            solve(maze, n, ans, visited, path, newx, newy);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    
public:
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string>ans;
        if(maze[0][0] == 0){
            return ans;
        }
        vector<vector<int>> visited = maze;
        
        int n = maze.size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                visited[i][j] = 0;
            }
        }
        
        int x = 0;
        int y = 0;
        
        string path = "";
        
        solve(maze, n, ans, visited, path, x, y);
        
        return ans;
    }
};