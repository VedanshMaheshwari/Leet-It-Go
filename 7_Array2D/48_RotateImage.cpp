

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> answer(row, vector<int>(col));
       
        for(int rowIndex = 0; rowIndex < row; rowIndex++){
            for(int colIndex = 0; colIndex < col; colIndex++){
                answer[colIndex][row - 1 - rowIndex] = matrix[rowIndex][colIndex];
                
            }
        }
        matrix = answer;

    }
};