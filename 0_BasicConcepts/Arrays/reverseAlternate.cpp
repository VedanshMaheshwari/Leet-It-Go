#include <iostream>
using namespace std;


void reverseAlt(int array[], int size){

    for(int i = 0; i < size; i+=2){
        if( i+1 < size){
            swap(array[i],array[i+1]);
        }
    }

}

int main(){

    int numEle;
    cin >> numEle;
    int array[numEle];

    for (size_t i = 0; i < numEle; i++){
        cin >> array[i];
    }

    int first = 0;
    int second = 1; 
    int temp = 0;

    while(second < numEle){
        temp = array[first];
        array[first] = array[second];
        array[second] = temp;

        first = first + 2;
        second = second + 2;
    }

    for (size_t i = 0; i < numEle; i++){
        cout << array[i];
    }

    cout << endl;

    reverseAlt(array, numEle);

    
    for (size_t i = 0; i < numEle; i++){
        cout << array[i];
    }


}