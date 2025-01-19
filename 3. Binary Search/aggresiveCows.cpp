#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

bool posibleSol(vector<int> &stalls, int k, int mid){

    int cow = 1;
    int lastPosition = stalls[0];
    
    for(int i = 0; i < stalls.size(); i++){
        if(stalls[i] - lastPosition >= mid){
            cow++;
            if(cow == k){
                return true;
            }
            lastPosition = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k){

    sort(stalls.begin(), stalls.end());
    int start = 0;
    int end = stalls[stalls.size()-1] - stalls[0];
    int mid = start + (end - start)/2;
    int ans = -1;
    while(start <= end){
        if(posibleSol(stalls,k,mid)){
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