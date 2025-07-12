#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    
    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    
    cout<< "Finding 4 in the vector -> "<< binary_search(v.begin(),v.end(),6)<<endl;

    cout<< "Upper Bound -> "<< upper_bound(v.begin(),v.end(),1) -v.begin()<< endl;
    cout<< "Lower Bound -> "<< lower_bound(v.begin(),v.end(),1) -v.begin()<< endl;

    cout<< max(v.front(),v.back())<<endl;
    cout<< min(v.front(),v.back())<<endl;
    // swap(v.front(),v.back());


    string abcd ="abcd";
    reverse(abcd.begin(),abcd.end());

    
    for (auto x : abcd) cout << x << " ";
    cout<<endl;

    rotate(v.begin(),v.begin()+1, v.end());

    for (int x : v) cout << x << " ";
    cout<<endl;

}