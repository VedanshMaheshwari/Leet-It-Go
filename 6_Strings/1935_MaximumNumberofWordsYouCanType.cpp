#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        
    unordered_set<char> hs;
    for(char c : brokenLetters){
        hs.insert(c);
    }

    stringstream ss(text);
    string word;
    int ans = 0;
    
    while (ss >> word) {
        bool valid = true;
        for(char c : word){
            if(hs.count(c)){
                valid = false;
                break;
            }
        }
        if(valid){
            ans++;
        }
    }
    return ans;
}
};