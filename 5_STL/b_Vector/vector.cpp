#include <iostream>
using namespace std;
#include <vector>


int main (){
    vector<int> v;
    vector<int>a(5,2);
    vector<int>b(a);

    cout<< v.capacity()<<endl;
    v.push_back(1);
    cout<< v.capacity()<<endl;
    v.push_back(1);
    cout<< v.capacity()<<endl;
    v.push_back(1);
    cout<< v.capacity()<<endl;
    v.push_back(1);
    cout<< v.capacity()<<endl;
    v.push_back(1);
    cout<< v.capacity()<<endl;


    for(int i:b){
        cout<< i << " ";
    }

    v.front();
    v.back();
    v.pop_back();
    v.clear();
    v.size();    
}