#include<iostream>
#include<vector>
using namespace std;


bool linearSearchRecursion(int array[] ,int size,int key){
    if(size == 0){
        return false; 
    }
    if(array[0] == key){
        return true;
    }
    else{
        bool remainingPart = linearSearchRecursion(array+1,size-1,key);
    }

}
