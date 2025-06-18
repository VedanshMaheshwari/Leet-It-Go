
// 33. Search in Rotated Sorted Array
// Solved
// Medium
// Topics
// Companies
// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1
 


#include<iostream>
#include <bits/stdc++.h>
using namespace std;

    int getPivot(vector<int>& nums){
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start)/2;
        while(start < end){
            
            if(nums[mid] < nums[end]){
                end = mid;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return start;
    }

    int binarySearch(vector<int>& nums,int startingElement, int endElement, int target){
        int start = startingElement;
        int end = endElement;
        int mid = start + (end - start)/2;
        
        while(start <= end){
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            } 
            else if(nums[mid] > target){
                end = mid - 1;
            }
             mid = start + (end - start)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int pivotElement = getPivot(nums);
        if(target >= nums[pivotElement] && target <= nums[nums.size()-1]){
            return binarySearch(nums, pivotElement, nums.size()-1, target);
        }
        else{
            return binarySearch(nums, 0 , pivotElement - 1, target);
        }
    }


int main(){

     vector <int> array ={7,19,1,2,3};

    int answer = search(array,1);

    cout << "The element is there at index: " << answer ;

    return 0;
}
