#include<iostream>

using namespace std;
class node{
private:
int value;
public:
  node *right;
  node *left;
  node(int value){
    this->value=value;
  }
  int getValue(){
    return this->value;
  }
  void insert(int value){
    if(this->value < value){
      if(right==nullptr){
        this->right=new node(value);
      }
      else{
        this->right->insert(value);
      }
    }
    else{
      if(left==nullptr){
        this->left=new node(value);
      }
      else{
        this->left->insert(value);
      }
    }
  }
};

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  node *root=new node(4);
  root->insert(3);
  root->insert(2);
  root->insert(8);
  root->insert(1);
  root->insert(7);
  root->insert(9);
  cout<<root->right->left->getValue();
}