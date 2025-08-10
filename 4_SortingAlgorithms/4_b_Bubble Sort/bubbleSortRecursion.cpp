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

int main(){

    vector<int> v = {294,21,43,12,41,1};
    bubbleSortRecursion(v,v.size());
    for(int num : v){
        cout << num << " ";
    }

}