#include<iostream>
#include<algorithm>
using namespace std;

bool valid(char ch){
    if(('a'<=ch && ch <='z') || ('A'<= ch && ch <='Z') || ('0' <= ch && ch <= '9')){
        return true;
    }
    return false;
}

char process(char ch){
    if(('a' <= ch && ch <= 'z')){
        return ch;
    }
    else if('A' <= ch && ch <= 'Z'){
        return (ch - 'A' + 'a');
    }
    else{
        return ch;
    }
}

bool checkPalindrome(string s){

    string temp = "";

    for(int i = 0; i<s.length(); i++){
        if(valid(s[i])){
            temp.push_back(s[i]);
        }
    }

    for(int i = 0; i<temp.length(); i++){
        temp[i] = process(temp[i]);
    }

    int start = 0;
    int end = temp.length() -1;
    while(start <= end){
        if(temp[start] != temp[end]){
            return false;
        }
        start ++ ;
        end -- ;
    }
    return true;
}


bool isPalindrome(string s) {
    
    string temp = "";

    for(int i = 0; i<s.length(); i++){
        if(valid(s[i])){
            temp.push_back(s[i]);
        }
    }

    // for(int i = 0; i<temp.length(); i++){
    //     temp[i] = process(temp[i]);
    // }

        int start = 0;
        int end = temp.length() -1;
        while(start <= end){
            if(process(temp[start]) != process(temp[end])){
                return false;
            }
            start ++ ;
            end -- ;
        }
        return true;
    }