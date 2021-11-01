#include<iostream>
using namespace std;
int gcd(a,b){
    return b!=0?gcd(b,a%b):a;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b);
}