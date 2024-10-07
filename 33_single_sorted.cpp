#include<iostream>
using namespace std;
int main(){
    int arr[5] = {1,1,3,5,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int X = 0;
    for(int i =0 ;i <n;i++){
        X = X^arr[i];
    }
    cout<<X;
}