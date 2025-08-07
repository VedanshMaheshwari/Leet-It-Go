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

int main(){
    int array [] = {1,2,4,5};
    
    bool answer = isSorted(array, 4);

    cout <<  answer ;
}