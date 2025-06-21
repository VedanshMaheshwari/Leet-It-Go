    bool ifPossible(vector<int>& nums, int k, int mid) {
        
    }

    int splitArray(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        // int start = *max_element(nums.begin(), nums.end());
        // int end = accumulate(nums.begin(), nums.end(), 0);
        for (int num : nums) {
            start = max(start, num); // same as max_element
            end += num;              // same as accumulate
        }
        int ans = -1;

        while(start <= end){
            int mid = start + (end - start) / 2;
            if(ifPossible(nums, k, mid)){
                ans = mid;
                end = mid - 1; // try smaller maximum sum
            }
            else{
                start = mid + 1;
            }
        }
        return ans;
    }