#include<iostream>
#include <bits/stdc++.h> 
#include "includeClass.cpp"
using namespace std;

class Hero{
    private:
        int health;

    public:
        char *name;
        char level;

    // Shallow Copy
    Hero(){
        cout<< "Simple constructor called" << endl;
        name = new char [100];
    }

    // Deep Copy
    Hero(Hero & temp){
        cout << "Copy constructor called" << endl;
        char *ch = new char [strlen(temp.name)+1];
        strcpy(ch, temp.name);
        this -> name = ch;
    }
};

int main(){

    Hero h1;
    includeClass object;

    cout << "Size of object is: " << object.age << endl;
}