#include<iostream>
using namespace std;



int main(){

    // the N element array will contain 1 to N-1 and any one element will be repeating twice
    int array[] = {1,3,2,2,3,4,1};
    
    int ans = 0;
    for (size_t i = 0; i < 7; i++){
        ans = ans^array[i];
    }

    for (size_t i = 0; i < 5; i++){
        ans = ans^i;
    }
    
   
    cout << ans;
}