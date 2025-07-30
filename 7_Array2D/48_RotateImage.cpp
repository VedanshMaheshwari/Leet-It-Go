

#include<iostream>
#include<vector>
#include<algorithm>
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

class Solution {
public:
void transpose(vector<vector<int>>& matrix){
    for (int rowIndex = 0; rowIndex < matrix.size(); rowIndex++) {
        for (int colIndex = rowIndex + 1; colIndex < matrix[0].size(); colIndex++) {
            swap(matrix[rowIndex][colIndex], matrix[colIndex][rowIndex]); 
        }
    }
}

    void rotate(vector<vector<int>>& matrix) {
        
        transpose(matrix);
        for(int i = 0; i < matrix.size(); i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};