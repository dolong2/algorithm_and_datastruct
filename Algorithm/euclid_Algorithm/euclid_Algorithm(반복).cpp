#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    while(b){
        int temp=a;
        a=b;
        b=temp%a;
    }
    cout<<a<<endl;
}