#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    bool ifPossi(vector<int>&nums,int k, int mid){
        int eleSum = 0;
        int splits = 1;
        for(int num : nums){
            if(eleSum + num <= mid){
                eleSum = eleSum + num;
            }else{
                splits++;
                if(splits > k ){
                    return false;
                }
                eleSum = 0;
                eleSum = eleSum + num;
            }
        }
        return true;
    }



    int splitArray(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        for(int num : nums){
            start = max(start, num);
            end = end + num;
        }
        int splits = 0;
        int ans = -1;
        while(start <= end){
    
            int mid = start + (end - start)/2;

            if(ifPossi(nums,k,mid)){
                ans = mid;
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }
};