#include<iostream>
using namespace std;
class Node {
    int data;
public:
    Node* link, * front;
    Node(int data, Node* link, Node* front) {
        this->data = data;
        this->front = front;
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
        newnode->front = tail;
    }
    tail = newnode;

}
void Delete(int idx) {
    if (idx != 1) {
        Node* target = head;
        Node* temp = head;
        for (int i = 0; i < idx - 2; i++) {//2
            head = head->link;
        }
        for (int i = 0; i < idx; i++) {
            target = target->link;
        }
        target->front = head;
        free(head->link);
        head->link = target;
        head = temp;
    }
    else {
        Node* temp = head;
        head = head->link;
        head->front = nullptr;
        free(temp);
    }
}
Node* left(Node* temp) {
    return temp->front;
}
Node* rigth(Node* temp) {
    return temp->link;
}
int main() {
    int n;
    cout << "데이터수: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cout << "데이터 입력: ";
        cin >> data;
        Node* newnode = new Node(data, nullptr, nullptr);
        insert(newnode);
    }
    cout << "지울 노드 번호(1번부터 시작): ";
    cin >> n;
    Delete(n);
    //head->print(head);
    Node* temp = head;
    cout << "현재 데이터: " << temp->getData()<<endl;
    while (true) {
        char n;
        cout << "정지는 S 왼쪽은 L 오른쪽은 R을 입력해주세요: ";
        cin >> n;
        if (n == 's' || n == 'S') {
            cout << "정지합니다" << endl;
            break;
        }
        else if (n == 'l' || n == 'L') {
            if (temp->front == nullptr) {
                cout << "제일 왼쪽에 있는 노드입니다" << endl;
                continue;
            }
            temp=left(temp);
        }
        else if (n == 'r' || n == 'R') {
            if (temp->link == nullptr) {
                cout << "제일 오른쪽에 있는 노드입니다" << endl;
                continue;
            }
            temp=rigth(temp);
        }
        cout << "현재 데이터: " << temp->getData() << endl;
    }
}