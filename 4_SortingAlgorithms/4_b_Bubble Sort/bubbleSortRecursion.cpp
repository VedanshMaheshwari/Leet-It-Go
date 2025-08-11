#include<iostream>
#include<vector>
using namespace std;

void bubbleSortRecursion(vector<int>&v,int size){
    if(size == 0 || size == 1){
        return ;
    }
    for(int i = 0; i < size-1; i++){
        if(v[i] > v[i+1]){
            swap(v[i], v[i+1]);
        }
    }
    bubbleSortRecursion(v,size-1);
}

void selectionSort(int v[] , int size){
    if(size == 0 || size == 1){
        return;
    }
    int min = 0;
    for(int i = 1; i < size; i++){
        min = v[0];
        if(min < v[i]) min = v[i];
    }
    v[0] = min;

    selectionSort(v+1,size-1);

}

int main(){

    int v[] = {294,21,43,12,41,1};
    int size = 6;
    //bubbleSortRecursion(v,size);
    for(int num : v){
        cout << num << " ";
    }

}