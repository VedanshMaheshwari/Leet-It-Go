#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    void reverse(vector<char>& s,int i, int j){
        if(i>j){
            return;
        }
        swap(s[i] , s[j]);
        return reverse(s,++i,--j);
    }

    void reverseString(vector<char>& s) {
        return reverse(s,0,s.size()-1);
    }
};

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size()-1;

        while(start < end){
            swap(s[start],s[end]);
            end--;
            start++;
        }
    }
};