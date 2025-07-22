#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols){
    vector<int> answer;
    for(int col = 0; col < mCols; col++){
        if(col % 2 == 0){
            for(int row = 0; row < nRows; row ++){
                answer.push_back(arr[row][col]);
            }
        }
        else{
            for(int row = nRows-1; row >= 0; row--){
                answer.push_back(arr[row][col]);
            }
        }
    }
    return answer;
}