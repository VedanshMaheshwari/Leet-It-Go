#include<iostream>
using namespace std;

void reverseString(char array[]){
    int start = 0;
    int end = 0;

    while (array[end] != '\0') {
        end++;
    }

    end = end - 1;

    while (start < end) {
        swap(array[start],array[end]);
        start++;
        end--;
    }
}

int main(){
    int n;
    cin >> n;
    char name[n];
    cin>>name;

    cout << "Before Swapping -> "<< name << endl;
    reverseString(name);
    cout << "After Swapping -> "<< name << endl;
}