#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

void solve(string str, vector<string>&answer, int index){
    if(index >= str.length()){
        answer.push_back(str);
        return;
    }

    for(int i = index; i < str.length(); i++){
        swap(str[index],str[i]);
        solve(str,answer,index+1);
        swap(str[index],str[i]);
    }
}


vector<string> generatePermutations(string &str){
    vector<string> answer;
    int index = 0;
    solve(str, answer, index);
    sort(answer.begin(), answer.end());
    return answer;
}