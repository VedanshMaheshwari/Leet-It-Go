#include<iostream>
#include<vector>;
using namespace std;


int partition(vector<int> &arr,int start, int end){
    
    int pivot = arr[start];
    int count = 0;
    for(int i = start+1 ; i <= end; i++){
        if(arr[i] <= pivot) count++;
    }

    int pivotIndex = start+count;
    swap(arr[start], arr[pivotIndex]);

    int i = start, j = end;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
     
        }
    }
    return pivotIndex;
}

void qs(vector<int>&arr,int start, int end){
    if(start >= end){
        return;
    }

    int p = partition(arr,start,end);

    qs(arr,start,p-1);
    qs(arr,p+1,end);
}

vector<int> quickSort(vector<int> arr){
    qs(arr,0,arr.size()-1);
    return arr;
}