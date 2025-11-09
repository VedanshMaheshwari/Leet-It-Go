#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int start, int end) {
        // deterministic better pivot: middle element
        int mid = start + (end - start) / 2;
        swap(nums[start], nums[mid]);

        int pivot = nums[start];
        int count = 0;

        // count elements strictly less than pivot (start+1 because start holds pivot)
        for (int i = start + 1; i <= end; ++i) {
            if (nums[i] < pivot) ++count;
        }

        int pivotIndex = start + count;
        swap(nums[start], nums[pivotIndex]);

        // MUST update pivot after moving it to pivotIndex
        pivot = nums[pivotIndex];

        int i = start, j = end;
        // move elements so that left side < pivot and right side >= pivot
        while (i < pivotIndex && j > pivotIndex) {
            while (i < pivotIndex && nums[i] < pivot) ++i;
            // IMPORTANT: use >= here to find elements strictly < pivot on the right
            while (j > pivotIndex && nums[j] >= pivot) --j;

            if (i < pivotIndex && j > pivotIndex) {
                swap(nums[i++], nums[j--]);
            }
        }

        return pivotIndex;
    }

    void quickS(vector<int>& nums, int start, int end) {
        if (start >= end) return;
        int p = partition(nums, start, end);
        quickS(nums, start, p - 1);
        quickS(nums, p + 1, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickS(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};
