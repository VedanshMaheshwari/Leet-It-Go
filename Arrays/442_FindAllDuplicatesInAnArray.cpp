#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums){
    
    sort(nums.begin(),nums.end());
    vector<int>array;
    for(int i = 0; i < nums.size()-1; i++){
        if(nums[i] == nums[i+1]){
            array.push_back(nums[i]);
        }
    }
    return array;
}


vector<int> findDuplicates(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans;
    for(int i=0; i<n; i++){
    int index = abs(nums[i])-1;
    if(nums[index] < 0){
        ans.push_back(abs(nums[i]));
    }
    else{
        nums[index] *= -1;
    }
}
    return ans;

}

int main(){

    int a;
    vector<int> array = {4,3,2,7,8,2,3,1};
    vector<int>res = findDuplicates(array);
    for (int i = 0; i < res.size(); i++)
    cout << res[i] << " ";
    return 0;
}