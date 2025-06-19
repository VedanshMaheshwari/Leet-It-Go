#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int start = 0;
    int end = nums.size() - 1;

    while (start < end) {
        int mid = start + (end - start) / 2;
        // Make mid even to compare with next index
        if (mid % 2 == 1) mid--;

        if (nums[mid] == nums[mid + 1]) {
            // Single element is after this pair
            start = mid + 2;
        } else {
            // Single element is before or at mid
            end = mid;
        }
    }
    // start == end is the index of the single element
    return nums[start];
}