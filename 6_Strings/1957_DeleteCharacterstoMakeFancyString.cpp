#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() <= 2) {
            return s;
        }
        int i = 0;
        while (i < s.length()) {
            char ch = s[i];
            int j = i;
            int count = 0;
            
            // Count the number of consecutive occurrences of s[i]
            while (j < s.length() && s[j] == ch) {
                count++;
                j++;
            }

            // If more than 2, erase the extra characters
            if (count > 2) {
                s.erase(i + 2, count - 2);
                // We don't need to update i here because 
                // after erasing, i is already at the correct position
            }
            
            // Move to next group (only 2 chars remain if count>2)
            i = i + min(2, count);
        }
        return s;
    }

    string makeFancyString(string s) {
        string res;
        for (char c : s) {
            int n = res.size();
            // Add only if it doesn't make 3 consecutive chars
            if (n >= 2 && res[n - 1] == c && res[n - 2] == c) {
                continue;
            }
            res.push_back(c);
        }
        return res;
    }
};
