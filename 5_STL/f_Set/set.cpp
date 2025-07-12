#include <iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;

    s.insert(5);
    s.insert(3);
    s.insert(5);
    s.insert(3);
    s.insert(0);
    s.insert(1);

    for(auto i : s){
        cout<<i<<endl;
    }

    s.erase(s.begin());

    for(auto i : s){
        cout<<i<<endl;
    }

    cout <<s.count(5) << endl; // count -> present or not  

    s.find(5); //refrence
    
}