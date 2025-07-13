#include<vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int i = 1; 
        for(; i < nums.size() ;i++){
            if(nums[i-1] > nums[i]){
                count ++;
            }
        }
        if(nums[nums.size()-1] > nums[0]){
            count ++;
        } 

        return count <= 1;
    }
};