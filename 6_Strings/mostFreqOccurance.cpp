#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        
        int array[26] = {0};
        int number = 0;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            number = ch - 'a';
            array[number]++;
        }
        
        int max = -1, ans = -1;
        for(int i = 0; i < 26;i++){
            if(max < array[i]){
                ans = i;
                max = array[i];
            }
        }
        
        char finalAns = 'a' + ans;
        return finalAns;
    }
};