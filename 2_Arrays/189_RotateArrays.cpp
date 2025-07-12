#include <iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n; // In case k > n

    vector<int> v(n);
    int index = 0;

    // Copy last k elements to the beginning of v
    for(int i = n - k; i < n; i++) {
        v[index++] = nums[i];
    }

    // Copy first n - k elements after that
    for(int i = 0; i < n - k; i++) {
        v[index++] = nums[i];
    }

    // Copy result back to nums
    for(int i = 0; i < n; i++) {
        nums[i] = v[i];
    }
}

    void rotate(vector<int>& nums, int k) {
        vector<int> temp (nums.size());
        for(int i = 0; i < nums.size(); i++){
            temp[(i+k) % nums.size()] = nums[i];
        }
        nums = temp;
    }