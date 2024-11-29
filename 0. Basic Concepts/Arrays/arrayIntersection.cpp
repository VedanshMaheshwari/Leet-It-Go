#include<iostream>
#include <bits/stdc++.h>
using namespace std;


vector<int> findArrayIntersection(vector<int>&arr1, int n,vector<int>&arr2, int m){

    
}

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n), arr2(m), res; 

    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    for (int j = 0; j < m; j++) {
        cin >> arr2[j];
    }

    int i= 0,j = 0;

    while(i < n && j < m){
        if(arr1[i] == arr2[j]){
            res.push_back(arr1[i]);
            i++, j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else{
            j++;
        }
    }

    for (int k = 0; k < res.size(); k++) {
        cout << res[k] << " ";
    }
    if (res.empty()) {
        return -1;
    }

    return 0;
}
