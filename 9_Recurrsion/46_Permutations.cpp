#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    
    void solve(vector<int> nums, vector<vector<int>>& answer, int index){
        //base case
        if(index >= nums.size()){
            answer.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++){
            swap(nums[index],nums[i]);
            solve(nums,answer,index+1);
        }
    }
    
    vector <vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        int index = 0;
        solve(nums, answer, index);
        return answer;
    }
};