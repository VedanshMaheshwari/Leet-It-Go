    #include<iostream>;
    #include<vector>;
    #include<algorithm>;
    using namespace std;


 // 2 POINTERS APPROACH    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> v(m + n); // Correct size for merged array
        int i = 0, j = 0, k = 0;
        // Merge until one array ends
        while(i < m && j < n) {
            if(nums1[i] < nums2[j]) {
                v[k++] = nums1[i++];
            } else {
                v[k++] = nums2[j++];
            }
        }
        // Copy remaining elements of nums1
        while(i < m) {
            v[k++] = nums1[i++];
        }
        // Copy remaining elements of nums2
        while(j < n) {
            v[k++] = nums2[j++];
        }
        // Copy back to nums1
        for(int x = 0; x < m + n; x++) {
            nums1[x] = v[x];
        }
    }

//STL APPROACH
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int j = 0, i = m; j<n; j++){
            nums1[i] = nums2[j];
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }

