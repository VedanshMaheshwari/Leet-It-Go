#include<iostream>
#include<vector>
using namespace std;


void reverseArray(int array[],int size){
        int temp = 0;
        for (int i = 0; i < size/2; i++)
        {
            temp = array[i];
            array[i] = array[size-1-i];
            array[size-1-i] = temp;
        }
}

// For vector, reverse after index m
void reverseArrayatM(vector<int> &arr, int m) {
    // reverse(arr.begin() + m + 1, arr.end());
}

void reverse(int array[], int size){
   
    int first = 0;
    int last = size -1;
    while(first <= last){
        swap(array[first], array[last]);
        first++;
        last--;
    }
}

int main(){

    int numOfElements;
    cin >> numOfElements;

    int array[numOfElements];

    for (size_t i = 0; i < numOfElements; i++)
    {
        cin >> array[i];
    }
    
    reverseArray(array,numOfElements);
    reverse(array, numOfElements);

    for (size_t i = 0; i < numOfElements; i++)
    {
        cout << array[i] << " ";
    }
    

}

