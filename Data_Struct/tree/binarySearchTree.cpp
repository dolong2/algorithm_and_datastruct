#include<iostream>
using namespace std;
class node{
  public:
  int data;
  node *left,*right;
  node(int key){
    data=key;
    left=nullptr;
    right=nullptr;
  }
};

node *insert(node *head,int key){
  if(head==nullptr){
    return new node(key);
  }
  else if(key>head->data){
    head->right=insert(head->right,key);
  }
  else{
    head->left=insert(head->right,key);
  }
  return head;
}
void postOrder(node *head){
  if(head!=nullptr){
    postOrder(head->left);
    postOrder(head->right);
    cout<<head->data<<endl;
  }
  else{
    return;
  }
}
int main(){
  int n;
  scanf("%d",&n);
  node *head;
  for(int i=0;i<n;i++){
    int data;
    scanf("%d",&data);
    if(i==0){
      head=insert(head,data);
    }
    else{
      insert(head,data);
    }
  }
}