#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isV(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxFreqSum(string s) {
        vector<int> freqV(26, 0); 
        vector<int> freqC(26, 0);

        for (char c : s) {
            if (isV(c)) {
                freqV[c - 'a']++;
            } else {
                freqC[c - 'a']++;
            }
        }

        int maxV = *max_element(freqV.begin(), freqV.end());
        int maxC = *max_element(freqC.begin(), freqC.end());

        return maxV + maxC;
    }
};

class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxV = 0, maxC = 0;
        for (int i = 0; i < 26; i++) {
            if (isVowel('a' + i)) 
                maxV = max(maxV, freq[i]);
            else 
                maxC = max(maxC, freq[i]);
        }

        return maxV + maxC;
    }
};
