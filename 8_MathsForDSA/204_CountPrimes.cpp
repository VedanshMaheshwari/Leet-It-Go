#include<vector>
#include<iostream>
using namespace std;


//Brute Force Method:
class Solution {
public:
    bool isPrime(int num){
        for(int i = 2; i < num; i++){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        int count = 0;
        for(int i = 2; i < n; i++){
            if(isPrime(i)){
                count++;
            }
        }  
        return count;  
    }
};


class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool>prime(n+1,true);
        prime[0] = prime[1] = false;

        for(int i = 2; i < n; i++){
            if(prime[i]){
                count++;
                for(int j=2*i ; j<n ; j=j+i){
                    prime[j] = false;
                }
            }
        }
        return count;
    }
};