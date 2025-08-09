#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1.0;
        }
        if(n == 1){
            return x;
        }
        double ans = pow(x, n/2);

        if(n % 2 ==0){
            return ans * ans;
        }
        else{
            return x * ans * ans;
        }
    }
};


class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; 

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return fastPow(x, N);
    }

private:
    double fastPow(double x, long long n) {
        if(n == 0){
            return 1.0;
        }
        if(n == 1){
            return x;
        }
        double ans = pow(x, n/2);

        if(n % 2 ==0){
            return ans * ans;
        }
        else{
            return x * ans * ans;
        }
    }
};