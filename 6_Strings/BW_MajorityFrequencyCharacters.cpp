using namespace std;
#include<iostream>
#include<string>
#include<map>
#include <vector>

string majorrityFrequencyGroup(string s){
    
    // s = "aaabbbccdde"
    // output -> ab

    map<char, int> freq;
    for(char c: s){
        freq[c]++;
    }

    map<int, vector<char>> group;
    for(auto freq_pair: freq){
        group[freq_pair.second].push_back(freq_pair.first);
    }

    int maxFreq = 0;
    int maxSize = 0;
    vector<char>ans;

    for(auto g: group){
        int f = g.first;
        int size = g.second.size();
        if(size > maxSize || (size == maxSize && f > maxFreq)){
            maxSize = size;
            maxFreq = f;
            ans = g.second;
        }
    }

    string result;
    for(char c: ans){
        result.push_back(c);
    }

    return result;
}