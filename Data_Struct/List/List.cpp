#include<iostream>
using namespace std;
class Node{
  int data;
  public:
  Node *link;
  Node(int data,Node *link){
    this->data=data;
    this->link=link;
  }
  int getData(){
    return data;
  }
  void print(Node *head){
    if(head!=nullptr){
      cout<<head->data<<"->";
      print(head->link);
    }
    else{
      cout<<"null";
      return;
    }
  }
};
int main(){
  int n;
  cin>>n;
  Node *head=nullptr;
  Node *tail=nullptr;
  for(int i=0;i<n;i++){
    int data;
    cin>>data;
    Node *newnode=new Node(data,nullptr);
    if(head==nullptr){
      head=newnode;
    }
    else{
      tail->link=newnode;
    }
    tail=newnode;
  }
  head->print(head);
}