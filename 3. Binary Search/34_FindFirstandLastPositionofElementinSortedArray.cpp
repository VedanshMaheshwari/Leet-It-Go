#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

int firstOcc(vector<int>& nums, int target){

    int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end-start)/2;
        int ans = -1;
        while (start <= end){
            if(nums[mid] == target){
                ans = mid;
                end = mid -1; 
            }
            else if(target < nums[mid]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
}

int lastOcc(vector<int>& nums, int target){
  
    int start = 0;
        int end = nums.size() -1;
        int mid = start + (end-start)/2;
        int ans = -1;
        while (start <= end){
            if(nums[mid] == target){
                ans = mid;
                start = mid + 1; 
            }
            else if(target < nums[mid]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end-start)/2;
        }
        return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums, target);
        int last = lastOcc(nums, target);

        return {first, last}; 
    }
};

