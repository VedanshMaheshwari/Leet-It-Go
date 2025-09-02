#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int n = image.size();
        int m = image[0].size();
        int startColor = image[sr][sc];

        if(startColor == color){
            return image;
        }

        queue<pair<int , int>>q;
        q.push({sr,sc});
        image[sr][sc] = color;

        int dr[]= {-1, 0, 1, 0};
        int dc[]= {0, 1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr>= 0 && newr<n && newc>=0 && newc<m && image[newr][newc] == startColor){
                    q.push({newr, newc});
                    image[newr][newc] = color;
                }
            }
        }
        return image;
    }
};