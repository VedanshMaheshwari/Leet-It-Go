#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int num;    
    cin >> num ;

    int i = 0;
    int binaryNumber = 0;

    int n = num;
    while (num != 0){
        int lastDigit = num % 10;
        binaryNumber = (lastDigit * pow(2,i) ) +  binaryNumber;
        i ++ ;
        num = num / 10;
    }

    cout <<"Decimal: "<< binaryNumber << endl;

}