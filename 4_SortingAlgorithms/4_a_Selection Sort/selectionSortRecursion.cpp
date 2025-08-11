#include<iostream>
#include<vector>
using namespace std;


void selectionSort(vector<int>& v, int size) {
    if (size <= 1) return;

    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (v[i] > v[maxIndex]) {
            maxIndex = i;
        }
    }
    swap(v[maxIndex], v[size - 1]);

    selectionSort(v, size - 1);
}

void selectionSortRecursive(vector<int> &v, int start) {
    if (start >= v.size() - 1) return; // base case

    // Find index of the smallest element from 'start' to end
    int minIndex = start;
    for (int j = start + 1; j < v.size(); j++) {
        if (v[j] < v[minIndex]) {
            minIndex = j;
        }
    }

    // Swap the smallest element with the first element of the unsorted part
    swap(v[start], v[minIndex]);

    // Recursive call for the rest of the array
    selectionSortRecursive(v, start + 1);
}

int main(){

    vector<int> v = {294,21,43,12,41,1};
    selectionSort(v,v.size());
    for(int num : v){
        cout << num << " ";
    }

}