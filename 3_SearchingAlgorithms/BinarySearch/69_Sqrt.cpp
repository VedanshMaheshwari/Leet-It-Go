#include<iostream>
#include<vector>

class Solution {
public:
    int mySqrt(int x) {
        

        int start = 0;
        int end = x;
        long long int mid = start + (end - start)/2; //overflow happens 0 <= x <= 231 - 1
        int ans = 0;
        while(start <= end){

            long long int sq = mid * mid;
            
            if(sq == x){
                return mid;
            }
            else if(sq < x){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
};