#include<iostream>
class Node {
  int data;
public:
  Node(int data, Node* link, Node* front) {
      this->data = data;
      this->link = link;
      this->front = front;
  }
  int getData() {
      return data;
  }
  Node* link, * front;
};
Node* push(int data, Node* back) {
  Node* newnode = new Node(data, nullptr, nullptr);
  if (back == nullptr) {
      back = newnode;
  }
  else {
      newnode->front = back;
      back->link = newnode;
      back = newnode;
  }
  return back;
}
Node* pop(Node* back) {
  if (back->front != nullptr) {
      Node* temp = back;
      back = temp->front;
      back->link = nullptr;
      free(temp);
      return back;
  }
  else {
      free(back);
      return nullptr;
  }
}
using namespace std;
int main() {
  Node* back = nullptr;
  while (true) {//S를 입력 받으면 멈춤
    string order;
    cin >> order;
    if (order == "Stop" || order == "stop") {
        cout << "종료합니다" << endl;
    }
    else if (order == "push" || order == "Push") {
        int data;
        cin >> data;
        back = push(data, back);
    }
    else if (order == "pop" || order == "Pop") {
      if(back!=nullptr)
        back = pop(back);
      else
        cout<<"스택이 비어있습니다!"<<endl;
    }
    else if (order == "empty" || order == "Empty") {
        if (back != nullptr) {
            cout << "false" << endl;
        }
        else {
            cout << "true" << endl;
        }
    }
    else if (order == "top" || order == "Top") {
        if (back != nullptr)
            cout << "data :" << back->getData() << endl;
        else
            cout << "비어있습니다!" << endl;
    }
    else {
        cout << "지정되지 않은 명령어!!" << endl;
    }
  }
}