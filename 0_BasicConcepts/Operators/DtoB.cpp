#include <iostream>
#include <cmath>
using namespace std;

int decimalToBinary(int n) {
    int number = 0;  
    int i = 0;       

    while (n != 0) {
        int digit = n & 1;           // Extract the least significant bit
        number += digit * pow(10, i); // Use addition instead of direct assignment
        n = n >> 1;                  // Right shift to move to the next bit
        i++;
    }

    return number;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    int i = 0;
    while(n != 0){
        int bit = n & 1;

        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i ++;
    }

    cout<< ans << endl;
}
