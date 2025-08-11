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

    void mergeSort(vector<int> &array, int start, int end){
        if(start >= end) return;
        int mid = (start + end) / 2;
        
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end); // ✅ FIX: changed to mid+1 so we sort the right half correctly

        merge(array, start, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }   
};