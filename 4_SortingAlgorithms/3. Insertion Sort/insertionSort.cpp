#include <bits/stdc++.h> 
#include <iostream>
using namespace std;

void insertionSort(int n, vector<int> &arr){
    for(int i = 1; i < n; i++){
        int j = i - 1;
        int temp = arr[i];    
        for( ;j >= 0; j--){
            if(arr[j] > temp){
                arr[j+1]=arr[j];
            }
            else{ // arr[j] < temp;
                break; 
            }
        }
        arr[j+1] = temp;
    }
}

void insertionSort(int n, vector<int> &arr){

    int i = 1;

    while(i < n){

        int j = i - 1;
        int temp = arr[i];
        while(j >= 0){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
        i++;
    }
}