#include <iostream>
using namespace std;

int main(){

    int numEle;
    cin >> numEle;

    int array[numEle];

    for (size_t i = 0; i < numEle; i++){~
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


}