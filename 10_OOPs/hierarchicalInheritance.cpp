#include<iostream>
using namespace std;

class A{
    public:
        void funcA(){
            cout << "Function A from class A" << endl;
        }
};

class B : public A{
    public:
        void funcB(){
            cout << "Function B from class B" << endl;
        }
};

class C : public A{
    public:
        void funcC(){
            cout << "Function C from class C" << endl;
        }
};

int main(){
    C d;
    d.funcA();
}
