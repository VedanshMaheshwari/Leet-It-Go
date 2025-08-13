#include<iostream>
#include<vector>
using namespace std;




// This is recursion solution - TLE only half test case passed.

class Solution {
public:
    bool existsInAns(const vector<string> &ans, const string &str) {
        for (const string &s : ans) {
            if (s == str) return true;
        }
        return false;
    }

    void solve(string &s, int index, string output, vector<string> &ans) {
        if (index >= s.length()) {
            if (!output.empty() && !existsInAns(ans, output)) {
                ans.push_back(output);
            }
            return;
        }
        // exclude current char
        solve(s, index + 1, output, ans);

        // include current char
        output.push_back(s[index]);
        solve(s, index + 1, output, ans);
    }

    int distinctSubseqII(string s) {
        vector<string> ans;
        string output = "";
        solve(s, 0, output, ans);
        return ans.size(); // already excludes empty subsequence
    }
};
