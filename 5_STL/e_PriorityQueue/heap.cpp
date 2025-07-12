#include <iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> maxi;                         // max heap by deafult;
    priority_queue<int,vector<int>,greater<int>>mini; // min heap
     
    maxi.push(1);
    maxi.push(3);
    maxi.push(4);
    maxi.push(2);
    int n = maxi.size();
    for(int i = 0 ; i < n; i ++){
        cout<<maxi.top()<<endl;
        maxi.pop();
    }

}