#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int TOPROW = x;
        int BOTTOMROW = x + k -1; 
        while(TOPROW < BOTTOMROW){
                for(int col = y; col < y + k; col++){
                    swap(grid[TOPROW][col],grid[BOTTOMROW][col]);
                }
                    TOPROW++;
                    BOTTOMROW--;
        }
        return grid;
    }
};