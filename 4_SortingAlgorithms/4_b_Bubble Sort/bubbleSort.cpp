#include<iostream>
#include<vector>
#include <bits/stdc++.h> 
using namespace std;

void bubbleSort(vector<int>& arr, int n){
int a = 0;
    for(int i = 1; i < n; i++){
        bool swapped = false;
        for(int j = 0;j < n-i ;j++){
            cout << a ;
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
            a++;
        }
        if(swapped == false){
            break;
        }
    }
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    bubbleSort(arr,arr.size());
}

