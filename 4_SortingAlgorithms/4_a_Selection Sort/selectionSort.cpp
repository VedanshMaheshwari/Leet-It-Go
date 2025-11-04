#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n){
    
    for(int i = 0; i < n; i++){
        int minIndex = i;
        for(int j = i+1 ; j < n; j++){
            if(arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
        // int t = arr[i];
        // arr[i] = arr[minIndex];
        // arr[minIndex] = t;
    }
}


int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();
    
    selectionSort(arr, n);
    
    cout << "Sorted array: \n";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

