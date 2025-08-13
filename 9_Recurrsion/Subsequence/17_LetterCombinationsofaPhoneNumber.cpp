#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    void solve(string digits, vector<string>&answer, string output, string map[], int index){

        if(index >= digits.length()){
            answer.push_back(output);
            return;
        } 

        int number = digits[index] - '0';
        string mappedValue = map[number];
        for(int i = 0; i < mappedValue.length(); i++){
            output.push_back(mappedValue[i]);
            solve(digits,answer,output,map,index+1);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            return {};
        }

        vector<string>answer;
        string output = "";
        int index = 0;
        string map[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        solve(digits,answer,output,map,index);
        return answer; 
    }
};