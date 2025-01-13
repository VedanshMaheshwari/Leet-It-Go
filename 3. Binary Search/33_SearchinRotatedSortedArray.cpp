
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

int getPivot(vector<int>& arr, int n){

    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start)/2;
    while(start < end){
        if(arr[mid] >= arr [0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int binarySearch(vector<int>& arr,int s,int e, int key){

    int start = s;
    int end = e;
    int mid = start + (end - start)/2;

    while(start <= end){

        if(arr[mid] == key){
            return mid;
        }

        else if (key > arr[mid] ){
            start = mid + 1;
        }

        else if (key < arr[mid]){
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }  
    return -1;
}
int search(vector<int>& nums, int target) {
    int pivot = getPivot(nums,nums.size()-1);
    if(target >= nums[pivot] && target <= nums[nums.size()-1]){
        return binarySearch(nums, pivot, nums.size()-1, target);
    }
    else{
        return binarySearch(nums, 0 , pivot - 1, target);
    }    
}


int main(){

     vector <int> array ={7,19,1,2,3};

    int answer = search(array,1);

    cout << "The element is there at index: " << answer ;

    return 0;
}
