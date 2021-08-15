#include<iostream>
using namespace std;
int arr[10]={2,3,1,4,7,0,5,6,8,9};
int linear_search(n){
    for(int i=0;i<10;i++){
        if(arr[i]==n)return i;
    }
    return -1;
}
int main(){
    int n;//찾을 숫자
    cin>>n;
    cout<<linear_search(n);
}