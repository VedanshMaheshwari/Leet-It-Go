#include <iostream>
#include <bits/stdc++.h>
using namespace std;    

bool uniqueOccurrences(vector<int>& arr) {

    vector<int> vec(arr.size(), 0);
    for(int i = 0; i < arr.size(); i++){
        int count = 0;
        for (int j = 0; j < arr.size(); j++){
            if(arr[i] == arr[j]){
                count ++;
            }
        }
        vec[i] = count; 
    }

    for (int a = 0; a < vec.size(); a++){
        for(int b = a+1; b < vec.size(); b++){
            if(vec[a] == vec[b] && arr[a] != arr[b]){
                return false;
            }
        }
    }
    return true;
}    



bool uniqueOccurrences(vector<int>& arr){
    int count=1;
    vector<int>v;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i=i+count){
        count=1;
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]==arr[j])
                count++;
        }
        v.push_back(count);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size()-1;i++)
    {
        if(v[i]==v[i+1])
            return false;
    }
    return true;
}


bool uniqueOccurrences(vector<int>& arr) {
    vector<int> vec; // To store frequencies of unique elements

    // Outer loop to calculate frequencies
    for (int i = 0; i < arr.size(); i++) {
        int count = 0;
        bool alreadyCounted = false;

        // Check if the element has already been processed
        for (int k = 0; k < i; k++) {
            if (arr[i] == arr[k]) {
                alreadyCounted = true;
                break;
            }
        }

        // Skip if the element is already processed
        if (alreadyCounted) continue;

        // Count occurrences of the current element
        for (int j = 0; j < arr.size(); j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        vec.push_back(count); // Store the frequency
    }

    // Check if all frequencies are unique
    for (int a = 0; a < vec.size(); a++) {
        for (int b = a + 1; b < vec.size(); b++) {
            if (vec[a] == vec[b]) {
                return false;
            }
        }
    }

    return true;
}
