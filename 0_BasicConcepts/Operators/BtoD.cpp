#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int num;    
    cin >> num ;

    int i = 0;
    int bn = 0;

    int n = num;
    while (num != 0){
        int ld = num % 10;
        bn = (ld * pow(2,i) ) +  bn;
        i ++ ;
        num = num / 10;
    }

    cout <<"Decimal: "<< bn << endl;

}