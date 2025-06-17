#include <iostream>
using namespace std;


int binarySearch(int arr[], int size, int key){

    int start = 0;
    int end = size -1;
    int mid = start + (end - start)/2;

    while(start <= end){

        if(arr[mid] == key){
            return mid;
        }

        else if (key > arr[mid] ){
            start = mid + 1;
        }

        else if (key < arr[mid]){
            end = mid - 1;
        }
        
        mid = start + (end - start)/2;
    }  
    return -1;
}


int main(){
    int num;
    cout << "Enter the number of elements in Array: ";
    cin >> num ;
    int array[num];

    for (int i = 0; i < num ; i++){
        cout<< "Enter the "<< i + 1 << " element: ";
        cin >> array[i];
    }

    int index = binarySearch(array, num, 297);
    cout << "The index of the key is: " << index;
}

int binarySearch(int arr[], int size, int num){
    
    int start = 0;
    int end = size;

    int middle = (start + end)/2;

    
}


