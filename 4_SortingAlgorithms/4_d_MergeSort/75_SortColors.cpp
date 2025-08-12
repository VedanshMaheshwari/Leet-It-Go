#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

void merge(vector<int> &array,int start, int end){
        int mid = (start + end) / 2;
        int length1 = mid - start + 1;
        int length2 = end - mid;

        vector<int> left(length1), right(length2);
        
        int arrayIndex = start; 
        for(int i = 0; i < length1; i++){
            left[i] = array[arrayIndex++];
        }

        arrayIndex = mid + 1;
        for(int j = 0; j < length2; j++){
            right[j] = array[arrayIndex++];
        }

        int index1 = 0, index2 = 0;
        arrayIndex = start;
        while(index1 < length1 && index2 < length2){
            if(left[index1] < right[index2]){
                array[arrayIndex++] = left[index1++];
            } else {
                array[arrayIndex++] = right[index2++];
            }
        } 

        while(index1 < length1){
            array[arrayIndex++] = left[index1++];
        }

        while(index2 < length2){
            array[arrayIndex++] = right[index2++];
        }
    }

    void mergeSort(vector<int>&nums, int start, int end){
        int mid = start + (end - start)/2;

        if(start >= end){
            return;
        }

        mergeSort(nums,start,mid);
        mergeSort(nums,mid+1,end);
        
        merge(nums,start,end);
    }


    void sortColors(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
    }
};