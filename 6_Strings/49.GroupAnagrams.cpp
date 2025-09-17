#include<iostream>
#include<algorithm>
#include <bits/stdc++.h> 
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> sorted;

        for(auto s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            sorted[temp].push_back(s);
        }

        for(auto x : sorted){
            ans.push_back(x.second);
        }

        return ans;
    }
};