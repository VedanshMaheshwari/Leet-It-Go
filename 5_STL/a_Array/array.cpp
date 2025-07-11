#include <iostream>
using namespace std;
#include <array>

int main(){
    array<int,4> a = {1,2,3,4};

    a.at(2);
    a.empty(); //Empty or Not;
    a.front();
    a.back();
}