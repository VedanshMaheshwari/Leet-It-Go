#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    bool isEqual(int a[], int b[]){
        int i = 0;
        while(i<26){
            if(a[i] != b[i]){
                return 0;
            }
            i++;
        }
        return 1;
    }

    bool checkInclusion(string s1, string s2) {
        int countS1[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            int index = s1[i] - 'a';
            countS1[index] = countS1[index] + 1;
        }
        
        int countS2[26] = {0};
        int windowSize = s1.length();
        int lengthS2 = s2.length();
        int i = 0;
        
        while(i < windowSize && i < lengthS2){
            int index = s2[i] - 'a';
            countS2[index] = countS2[index] + 1;
            i++;
        }

        if(isEqual(countS1 , countS2)){
            return 1;
        }

        while(i < lengthS2){
            
            int index = s2[i] - 'a';
            countS2[index] = countS2[index] + 1;

            index = s2[i - windowSize] - 'a';
            countS2[index]--;
            i++;

            if(isEqual(countS1 , countS2)){
            return 1;
            }
        }
        return 0;
    }
};