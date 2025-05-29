#include<iostream>
using namespace std;



int findUnique(int array[], int size) {
    for (size_t i = 0; i < size; i++) {
        bool isUnique = true; // Assume the current element is unique

        for (size_t k = 0; k < size; k++) {
            if (i != k && array[i] == array[k]) { // Check if any other element matches
                isUnique = false;
                break; // No need to check further if a match is found
            }
        }

        if (isUnique) {
            return array[i]; // Return the unique element
        }
    }

    return -1; // Return -1 if no unique element is found
}


int findUnique(int array[], int size) {
    for (size_t i = 0; i < size; i++) {
        int count = 0; // Initialize count for the current element

        for (size_t k = 0; k < size; k++) {
            if (array[i] == array[k]) {
                count++; // Increment count for each match
            }
        }

        if (count == 1) { // If count is 1, this is the unique element
            return array[i];
        }
    }

    return -1; // Return -1 if no unique element is found
}

int main (){
    
    //arry has only one unique element rest elements are in pair of 2.
    int array[] = {1,2,3,4,3,2,1};

    int ans = findUnique(array, 7);
    
    cout << ans;


    return 0;
}
