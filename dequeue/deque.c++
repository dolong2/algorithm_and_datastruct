#include<iostream>
#include<vector>
using namespace std;
vector<int>deq;
void push_front(int a){
  deq.insert(deq.begin(),a);
}
void push_back(int a){
  deq.push_back(a);
}
void front(){
  printf("%d\n",deq.front());
}
void back(){
  printf("%d\n",deq.back());
}
void size(){
  printf("%ld\n",deq.size());
}
void empty(){
  int a=deq.empty()?1:0;
  printf("%d\n",a);
}
void pop_front(){
  printf("%d\n",deq.front());
  deq.erase(deq.begin());
}
void pop_back(){
  printf("%d\n",deq.back());
  deq.pop_back();
}
int main(){
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    string str;
    cin>>str;
    if(str=="push_front"){
      int a;
      scanf("%d",&a);
      push_front(a);
    }
    else if(str=="push_back"){
      int a;
      scanf("%d",&a);
      push_back(a);
    }
    else if(str=="front"){
      if (deq.size()!=0)
        front();
      else
        printf("-1\n");
    }
    else if(str=="back"){
      if (deq.size()!=0)
        back();
      else
        printf("-1\n");
    }
    else if(str=="pop_front"){
      if (deq.size()!=0)
        pop_front();
      else
        printf("-1\n");
    }
    else if(str=="pop_back"){
      if (deq.size()!=0)
        pop_back();
      else
        printf("-1\n");
    }
    else if(str=="empty"){
      empty();
    }
    else if(str=="size"){
      size();
    }
  }
}