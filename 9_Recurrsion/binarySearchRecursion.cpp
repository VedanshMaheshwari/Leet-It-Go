#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int bSearch(vector<int>& nums, int start, int end, int target) {
        if(start > end){
            return -1;
        }

        int mid = start + (end - start)/2;
        
        if(nums[mid] == target) return mid;
        if(nums[mid] > target){
            return bSearch(nums, start, mid - 1 ,target);
        }else{
            return bSearch(nums, mid + 1, end, target);
        }
    }

    int search(vector<int>& nums, int target) {
        return bSearch(nums, 0, nums.size() - 1, target);
    }
};