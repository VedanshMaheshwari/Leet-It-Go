#include<iostream>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
    stack<char> Stack;

    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (!Stack.empty() && s[i] == Stack.top()) {
            Stack.pop(); 
        } else {
            Stack.push(s[i]); 
        }
    }
    while (!Stack.empty()) {
        result += Stack.top();
        Stack.pop();           
    }
    reverse(result.begin(), result.end());
    return result;
    }

    string removeDuplicates(string s) {
    string result = "";
    
        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                result.pop_back();  // Remove last character
            } else {
                result.push_back(c);  // Add new character
            }
        }

        return result;
    }
};