#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    char name[n];
    cin >> name;

    int count = 0;
    for(int i = 0; name[i] != '\0'; i++){
        count ++;
    }

    cout<< "the lenghth of string is -> " << count;

}
