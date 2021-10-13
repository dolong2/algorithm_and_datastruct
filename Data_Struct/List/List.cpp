#include<iostream>
using namespace std;
class Node {
    int data;
public:
    Node* link;
    Node(int data, Node* link) {
        this->data = data;
        this->link = link;
    }
    int getData() {
        return data;
    }
    void print(Node* head) {
        if (head != nullptr) {
            cout << head->data << "->";
            print(head->link);
        }
        else {
            cout << "null";
            return;
        }
    }
};
Node* head = nullptr;
Node* tail = nullptr;
void insert(Node* newnode) {
    if (head == nullptr) {
        head = newnode;
    }
    else {
        tail->link = newnode;
    }
    tail = newnode;
    tail->link=head;
}
void Delete(int idx) {
  if(idx!=1){
    Node* target = head;
    Node* temp = head;
    for (int i = 0; i < idx - 2; i++) {//2
        head = head->link;
    }
    for (int i = 0; i < idx; i++) {
        target = target->link;
    }
    free(head->link);
    head->link = target;
    head = temp;
  }
  else{
    Node *temp=head;
    head=head->link;
    tail->link=head;
    free(temp);
  }
}
void cnt_order(int cnt){
  Node *temp=head;
    for(int i=0;i<cnt-1;i++){
      temp=temp->link;
    }
    cout<<"순회결과: "<<temp->getData()<<endl;
}//순회 횟수 정해서 순회
int main() {
    int n;
    cout << "데이터수: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cout << "데이터 입력: ";
        cin >> data;
        Node* newnode = new Node(data, nullptr);
        insert(newnode);
    }
    cout<<"지울 노드 번호(1번부터 시작): ";
    cin >> n;
    Delete(n);
    //head->print(head);//원형 리스트에서 순회는 끝없이 할 수 있다
    int cnt;
    cout<<"몇번 순회할지 입력: ";
    cin>>cnt;
    cnt_order(cnt);
}