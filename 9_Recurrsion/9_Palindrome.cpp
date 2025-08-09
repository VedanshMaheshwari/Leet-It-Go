#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool check(string& s, int i, int j){
        if(i>=j){
            return true;
        }
        if(s[i] != s[j]){
            return false;
        }
        return check(s,++i,--j);
    }

    bool isPalindrome(int x) {
        string s = to_string(x);
        return check(s,0,s.length()-1);
    }
};