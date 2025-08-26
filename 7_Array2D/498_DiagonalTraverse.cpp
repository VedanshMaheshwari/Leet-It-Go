#include<iostream>
#include<vector>
using namespace std;    

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int row = mat.size();
        int col = mat[0].size();
        int total = row*col;
        vector<int> ans;
        
        int startRow = 0;
        int startCol = 0;
        bool goingUp = true;

        while(ans.size() < total){
            ans.push_back(mat[startRow][startCol]);
            
            if(goingUp){
                if(startCol == col - 1){
                    startRow ++;
                    goingUp = false;
                }else if(startRow == 0){
                    startCol++;
                    goingUp = false;
                }else{
                    startRow--;
                    startCol++;
                }
            }
            else{
                if(startRow == row - 1){
                    startCol ++;
                    goingUp = true;
                }else if(startCol == 0){
                    startRow++;
                    goingUp = true;
                }else{
                    startRow++;
                    startCol--;
                }
            }
        }
        return ans;
    }
};