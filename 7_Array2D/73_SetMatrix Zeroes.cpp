#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    //BRUTE FORCE SOLUTION:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int column = matrix[0].size();

        int rowIndex;
        int colIndex;
        int endingRow = row - 1;
        int endingCol = column - 1;

        // Choose a marker that cannot appear in matrix. INT_MIN is a good candidate.
        const int MARKER = 1e9 + 7; // Use a value highly unlikely to appear (Leetcode matrices usually use small ints)

        for(rowIndex = 0; rowIndex < row; rowIndex++){
            for(colIndex = 0; colIndex < column; colIndex++){
                if(matrix[rowIndex][colIndex] == 0){
                    for(int i = 0; i <= endingCol; i++){
                        if(matrix[rowIndex][i] == 0 || matrix[rowIndex][i] == MARKER){
                            continue;
                        }else{
                            matrix[rowIndex][i] = MARKER;
                        }    
                    }
                    for(int i = 0; i <= endingRow; i++){
                        if(matrix[i][colIndex] == 0 || matrix[i][colIndex] == MARKER){
                            continue;
                        }else{
                            matrix[i][colIndex] = MARKER;
                        }    
                    }
                }
            }
        }

        // Now convert marker to 0
        for(rowIndex = 0; rowIndex < row; rowIndex++){
            for(colIndex = 0; colIndex < column; colIndex++){
                if(matrix[rowIndex][colIndex] == MARKER){
                    matrix[rowIndex][colIndex] = 0;
                }
            }
        }
    }
};
