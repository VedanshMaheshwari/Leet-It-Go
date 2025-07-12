#include<iostream>
#include<map>
using namespace std;

int main(){

    map<int,string> m;
    m[1] = "maheshwari";
    m[2] = "vedansh";
    m[10] = "raj";
    m.insert({5,"bheem"});
    for(auto i : m){
        cout << i.second << endl;
    }
    m.count(10);
    m.erase(13);

    auto it = m.find(2);

    for(auto i = it; i != m.end() ; i++){
        cout<< (*i).second ;  
    }


}  