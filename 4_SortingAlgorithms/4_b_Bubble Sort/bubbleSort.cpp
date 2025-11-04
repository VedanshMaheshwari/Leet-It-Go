#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;

void bubbleSort(vector<int>& arr, int n){
int a = 0;
    for(int i = 1; i < n; i++){
        bool swapped = false;
        for(int j = 0;j < n-i ;j++){
            // cout << a ;
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
            // a++;
        }
        if(swapped == false){
            break;  
        }
    }
}

void bubbleSort(vector<int>& arr){
    int n = arr.size();
    for(int i = n-1; i >= 1; i--){
        for(int j = 0; j < n; j ++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

int main(){
    vector<int> arr = {11, 20, 13, 40, 15};
    bubbleSort(arr);

    for(int num : arr){
        cout << num << " ";
    }
}

