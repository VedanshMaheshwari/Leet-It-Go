#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    vector<vector<int>>ans;
    vector<int> temp;

    for(int i = 0; i < arr.size(); i++){
        for(int j=i+1; j < arr.size(); j++){
            for(int k=j+1 ; k < arr.size(); k++){
                if(arr[i]+ arr[j]+ arr[k] == K){
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    ans.push_back(temp);

					for (int a = 0; a < temp.size(); a++){
						cout << temp[a] << " ";
					}	
								
                }
				cout << endl ;
			
            }
		
        }
		
    }
    return ans;
}

int main() {
    // Example input
    vector<int> arr = {10,5,5,5,2};
    int K = 12;  // Target sum for the triplets

    // Calling the function
    vector<vector<int>> result = findTriplets(arr, arr.size(), K);
	

}
