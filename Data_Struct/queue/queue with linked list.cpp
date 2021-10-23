#include<iostream>
using namespace std;
class Node{
  int data;
  public:
  Node(int data,Node *link){
    this->data=data;
    this->link=link;
  }
  int getData(){
    return data;
  }
  Node *link;
};
Node *head=nullptr;
Node *tail=nullptr;
void push(int data){
  Node *newnode=new Node(data,nullptr);
  if(head==nullptr){
    head=newnode;
  }
  else{
    tail->link=newnode;
  }
  tail=newnode;
}
void pop(){
  Node *temp=head;
  head=head->link;
  free(temp);
}
int main(){
  while(true){
    cout<<"명령어를 입력해주세요: ";
    string order;
    cin>>order;
    if(order=="Push"||order=="push"){
      int data;
      cin>>data;
      push(data);
    }
    else if(order=="Pop"||order=="pop"){
      if(head!=nullptr)
        pop();
      else
        cout<<"큐가 비어있습니다\n";
    }
    else if(order=="empty"||order=="Empty"){
      if(head==nullptr)
        cout<<"True\n";
      else
        cout<<"False\n";
    }
    else if(order=="Front"||order=="front"){
      if(head==nullptr)
        cout<<"큐가 비어있습니다\n";
      else
        cout<<"Data: "<<head->getData()<<"\n";
    }
    else if(order=="Back"||order=="back"){
      if(head==nullptr)
        cout<<"큐가 비어있습니다\n";
      else
        cout<<"Data: "<<tail->getData()<<"\n";
    }
    else if(order=="Stop"||order=="stop"){
      cout<<"중단합니다"<<endl;
      break;
    }
  }
}