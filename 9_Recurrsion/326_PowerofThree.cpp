#include<iostream>
using namespace std;

class Solution {
public:

    bool powerThree(int n){
        if(n == 1){
            return true;
        }
        
        if(n <= 0 || n % 3 != 0){
            return false;
        }
        return powerThree(n/3);
    }

    bool isPowerOfThree(int n){
        return powerThree(n);
    }
};