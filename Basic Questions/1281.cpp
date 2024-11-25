#include <iostream>
using namespace std;



int subtractProductAndSum(int n) {
    int num = n;
    int sum= 0, prod =1;
    while(num != 0){
        int lastDigit = num % 10;
        num = num / 10;

        sum = sum + lastDigit;
        prod = prod * lastDigit;
    } 
    return (prod - sum);
}

int main(){

    int n = subtractProductAndSum(100);
    cout << n << endl;
    return 0;
}