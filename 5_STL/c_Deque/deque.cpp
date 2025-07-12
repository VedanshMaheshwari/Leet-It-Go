#include <iostream>
#include<deque>
using namespace std;


int main(){

    deque<int>d;

    d.push_back(2);
    d.push_front(1);
    d.pop_front();
    d.pop_back();
    d.at(1);
    d.front();
    d.back();
    d.erase(d.begin(),d.begin() + 1);
    
}
