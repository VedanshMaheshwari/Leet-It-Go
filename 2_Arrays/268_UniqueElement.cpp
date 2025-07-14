    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int end = nums.size()-1;
        int start = 0;

        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == mid){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return start;
    }