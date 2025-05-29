#include<iostream>
#include<vector>
using namespace std;


int possibleSol(vector<int> &boards, int n, int k , int mid){

    int painter = 1;
    int time = 0;

    for(int i = 0; i < n; i++){
        if(time + boards[i] <= mid){
            time = time + boards[i];
        }
        else{
            painter++;
            if(painter > k || boards[i] > mid){
                return false;
            }
            time = boards[i];
        }
    }
    return true;
}



int findLargestMinDistance(vector<int> &boards, int k) {
  int start = 0;
  int sum = 0;
  int n = boards.size();
  for (int i = 0; i < n; i++){
      sum += boards[i];
  }

  int end = sum;
  int mid = start +(end - start)/2;
  int ans = -1;

  while(start <= end){
    if((possibleSol(boards,n,k,mid))){
      ans = mid;
      end = mid - 1;
    }else{
        start = mid + 1;
    }
    mid = start +(end - start)/2;
  }
  return ans;
}