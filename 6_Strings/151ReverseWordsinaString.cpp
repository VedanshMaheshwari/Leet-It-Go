#include<iostream>
#include<algorithm>
#include<vector>
#include <sstream>
using namespace std;

    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int left = 0;
        int right = 0;
        int i = 0;
        while (i < n) {
            while (i < n && s[i] == ' ')
                i++;
            if (i == n)
                break;
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }
            reverse(s.begin() + left, s.begin() + right);
            s[right++] = ' ';
            left = right;
            i++;
        }
        s.resize(right - 1);
        return s;
    }


    string reverseWords(string s) {
        stringstream ss(s);
        string word;

        vector<string> words;

        while(ss >> word){
            words.push_back(word);
        }
        s = "";
        for(int i = words.size()-1; i >= 0 ; i--){
            s = s + words[i];
            if(i != 0){
                s = s + " ";
            }
        }
        return s;    
    }

