#include<iostream>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  unsigned int bit=0;//집합??
  cin>>n;
  for(int i=0;i<n;i++){
    string order;
    int x;
    cin>>order;
    if(order=="add"){
      cin>>x;
      bit|=(1<<x);
    }
    else if(order=="remove"){
      cin>>x;
      if(bit&(1<<x)){
        bit&=~(1<<x);
      }
      else{
        continue;
      }
    }
    else if(order=="check"){
      cin>>x;
      if(bit&(1<<x)){
        cout<<"1\n";
      }
      else{
        cout<<"0\n";
      }
    }
    else if(order=="toggle"){
      cin>>x;
      bit^=(1<<x);
    }
    else if(order=="all"){
      bit=(1<<21)-1;
    }
    else{
      bit=0;
    }
  }
} 