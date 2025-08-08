#include<iostream>
using namespace std;

bool isSorted(int *array, int size){
    if(size == 0 || size == 1){
        return true;
    }
    if(array[0] > array[1]){
        return false;
    }else{
        bool ans = isSorted(array + 1, size -1);
        return ans;
    }

}

int sumArray(int *array, int size){
    if (size == 0) return 0;
    if (size == 1) return array[0];
    int ans = array[0] + sumArray(array+1,size-1);
    return ans; 
}

int main(){
    int array [] = {3,2,5,1,6};
    
    int answer = sumArray(array, 5);


    cout <<  answer ;
}