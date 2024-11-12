#include<iostream>
#include <cmath>
using namespace std;

int reverse(int x){
    int answer = 0;
    while(x!=0){
        int digit = x % 10;
        if((answer > INT32_MAX/10) || (answer < INT32_MIN/10)){
            cout<< "0" <<endl;
            return 0;
        }
        answer = answer * 10 + digit;
        x = x /10;
    }
    cout << answer << endl ;
    return answer;
}

int main(){

    int a = reverse(746384713);
    return 0;
}