#include<iostream>
using namespace std;

class Animal{

    private:
        int age;
        int weight;

    public:
        void speak(){
            cout << "Animal speaks" << endl;
        }
};



class Human {
    public:
        void think(){
            cout << "Human thinks" << endl;
        }
};


class hybrid : public Animal, public Human {
    public:
        void run(){
            cout << "Hybrid runs fast" << endl;
        }
};



int main(){
    hybrid d;
    d.speak();
    d.think();
}
