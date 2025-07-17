#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void reverseWords(vector<char> &s){
    // Step 1: Reverse the whole string
    reverse(s.begin(), s.end());

    int n = s.size();
    int i = 0;
    
    while(i < n) {
        // Skip leading spaces
        while(i < n && s[i] == ' ') i++;

        // Start of the word
        int j = i;

        // Move to the end of the word
        while(j < n && s[j] != ' ') j++;

        // Reverse the word from i to j - 1
        reverse(s.begin() + i, s.begin() + j);

        // Move i to j to continue with next word
        i = j;
    }
}

int main () {
    vector<char> s = {'b', 'l', 'u', 'e',' ','s','e','a'};
    reverseWords(s);
 
    for(char a : s){
        cout << a;
    }
    cout << endl;

    return 0;
}
