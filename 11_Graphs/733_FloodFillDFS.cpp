#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


class Solution {
public:

    void dfs(vector<vector<int>>& image, int row, int col, int color, int startColor, int n, int m){
        
        if(!(row >= 0 && row < n && col >= 0 && col < m && image[row][col]==startColor)){
            return;
        }

        image[row][col] = color;

        dfs(image, row+1, col, color, startColor, n, m);
        dfs(image, row, col+1, color, startColor, n, m);
        dfs(image, row-1, col, color, startColor, n, m);
        dfs(image, row, col-1, color, startColor, n,m);        

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int startColor = image[sr][sc];
        
        if(startColor == color){
            return image;
        }

        dfs(image, sr, sc, color, startColor, n, m);        
        return image;
    }
};