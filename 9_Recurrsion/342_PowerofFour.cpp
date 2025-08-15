#include<iostream>
#include<vector>
using namespace std;


bool fourPower(int n){
    if(n == 1){
        return true;
    }
    
    if(n <= 0 || n % 4 == 0){
        return false;
    }
    return(n/4);
}

int main(){

    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    bool answer = fourPower(n);

    if(answer){
        cout << "Its power of 4";
    }else{
        cout << "Its not a power of 4";
    }
}