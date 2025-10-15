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

class Dog : public Animal{
    public:
        void bark(){
            cout << "Dog barks" << endl;
        }
};


class germanShepherd : public Dog{
    public:
        void run(){
            cout << "German Shepherd runs fast" << endl;
        }
};


int main(){
    germanShepherd d;
    d.speak();
}
