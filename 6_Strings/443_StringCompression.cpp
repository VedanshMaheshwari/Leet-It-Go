#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int j = 0;
        int n = chars.size();
        vector<char> ans;

        while (i < n) {
            int count = 0;  // Reset count for each group
            ans.push_back(chars[i]);  // Add the character

            // Count the number of consecutive characters
            while (j < n && chars[i] == chars[j]) {
                count++;
                j++;
            }

            // If count > 1, append its digits
            if (count > 1) {
                vector<char> digits;
                while (count != 0) {
                    int lastDigit = count % 10;
                    count = count / 10;
                    digits.push_back('0' + lastDigit);  // Convert int to char
                }
                reverse(digits.begin(), digits.end());
                for (char a : digits) {
                    ans.push_back(a);
                }
            }
            i = j;  // Move to next group
        }

        // Copy ans back to chars
        chars = ans;
        return chars.size();
    }
};