#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long time(vector<int>& piles, long long mid) {
        long long sum = 0;
        for (int num : piles) {
            sum += ceil((double)num / mid);
        }
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        long long end = 0;
        int ans = 0;

        for (int num : piles) {
            end += num;
        }

        while (start <= end) {
            long long mid = start + (end - start) / 2;
            long long reqTime = time(piles, mid);

            if (reqTime <= h) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};
