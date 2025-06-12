#include <iostream>
using namespace std;

int fib(int n){
    int a = 0, b = 1;
    int c = 0;

    for (int i = 0; i <= n; i++){
        if(i == 0){
            cout << a << endl;

        }
        if(i == 1){
            cout << b << endl;
        }

        c = a + b;
        a = b;
        b = c;
        cout << c << endl;
    }
}

int main(){
    fib(5);
}
   