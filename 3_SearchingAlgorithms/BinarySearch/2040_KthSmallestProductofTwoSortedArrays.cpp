   #include<iostream>
   #include<vector>
   #include <bits/stdc++.h>
   
   using namespace std;

    
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<long long> products;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                products.push_back((long long)nums1[i] * nums2[j]);
            }
        }
        sort(products.begin(), products.end());
        return products[k - 1];
    
    }


    long long countPairs(vector<int>& A, vector<int>& B, long long x) {
        long long count = 0;
        int n = B.size();

        for (int a : A) {
            if (a > 0) {
                // Binary search in B: find largest j where a * B[j] <= x
                int low = 0, high = n - 1, pos = -1;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if ((long long)a * B[mid] <= x) {
                        pos = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                count += (pos + 1);  // indices 0..pos
            } else if (a < 0) {
                // Binary search in B: find smallest j where a * B[j] <= x
                int low = 0, high = n - 1, pos = n;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if ((long long)a * B[mid] <= x) {
                        pos = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                count += (n - pos);  // indices pos..n-1
            } else { // a == 0
                if (x >= 0) count += n; // all products 0 <= x
            }
        }

        return count;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long low = -1e10, high = 1e10, ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long cnt = countPairs(nums1, nums2, mid);

            if (cnt >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }