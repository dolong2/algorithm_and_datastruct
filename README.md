<h1>자료구조 & 알고리즘</h1>

- **빅오표기법**
    - 알고리즘의 효율도를 분석하는 방법
    - **기본적으로, 알고리즘 최악의 경우의 복잡도를 측정**
    - 표기: ex)O(n),O(log n),O(1)

- [**스택**](Data_Struct/stack/stack.md)
    

- [**큐**](Data_Struct/queue/queue.md)
    

- [ **덱(dequeue)** ](Data_Struct/dequeue/dequeue.md)
    

- **서치(알고리즘)**
    - [선형서치(Linear Search)](Algorithm/search/linearsearch/linearsearch.md)
    - [이진서치(Binary Search)](Algorithm/search/binarysearch/binarysearch.md)

- **정렬(알고리즘)**
    - [선택정렬](Algorithm/sort/선택정렬/선택정렬.md)
    - [삽입정렬](Algorithm/sort/삽입정렬/insertSort.md)
    - [버블정렬](Algorithm/sort/버블정렬/bubbleSort.md)
    - 퀵정렬
    - 합병정렬
    - [쉘정렬](Algorithm/sort/쉘정렬/shellSort.md)


- [**그래프(Graph)**](./Data_Struct/Graph/graph.md)
        

- [**트리(tree)**](./Data_Struct/tree/tree.md)

- **리스트(List)**
    - 각 노드가 데이터와 포인터를 가지고 있고 한 줄로 연결되어 있는 선형적 자료구조이다
    - 자료 추가와 삭제가 O(1)의 시간 복잡도를 가진다는 장점이 있다
    - 특정 데이터의 위치를 찾는데 O(n)의 시간 복잡도를 가진다는 단점도 있다
        
        ## 종류
        
        - 단일 연결 리스트
            
            노드에 자료 공간과 한 개의 포인터 공간이 있고, 각 노드의 포인터는 다음 노드를 가리키는 리스트
            ```cpp
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
            ```
        - 이중 연결 리스트
            
            단일 연결 리스트와 비슷하지만, 포인터 공간이 두 개가 있고 각각의 포인터는 앞의 노드와 뒤의 노드를 가리키는 리스트
- **유클리드 알고리즘** 
  - 두수의 최대공약수를 구하는 알고리즘
  - 두수 a,b와 나머지를 r이라고 하면 a와b의 최대공약수는 b와 r의 최대공약수와 같다
  - 즉 b를 r로 나눈 나머지 r2를 구하고 다시 r을 r2로 나눈 나머지를 구하는 과정을 반복하여 나머지가 0이 되었을 때 나누는 수가 a와 b의 최대공약수이다
    ## 코드     
    반복문을 사용해서 구하는 방법과 재귀 함수를 사용하는 방법이 있다 
    ```cpp
    //반복문을 사용해서 구현
    #include<iostream>
    using namespace std;
    int main(){
      int a,b;
      cin>>a>>b;
      while(b){
          int temp=a;
          a=b;
          b=temp%a;
      }
      cout<<a<<endl;
    }
    ```

    ```cpp
    //재귀 함수+3항 연산자(3항 연산자 모르면 구글링 하셈)
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
    ```
- **비트 마스킹** 
  - 정의
    - 정수의 이진수 표현을 자료구조로 쓰는 기법
  - 장점
    - 메모리를 아낄 수 있고 더 빠른 수행 시간을 가지고 있음
  - 단점
    - 비트를 다뤄야해서 구현 난이도와 활용도가 상당히 높은 편
    ### 집합 구현 ###
    ```cpp
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
    ```
---

[스택 명령어](https://www.notion.so/962e13d092f74a63aff103dc89911e88)

[큐 명령어](https://www.notion.so/941794de4b0248cfaeb68b08181d03a7)

[선형서치](https://www.notion.so/596715d04a104c52a6193e258fc07908)

[이진서치](https://www.notion.so/c8b7a6fc4bd24627969c4ad99f09d99c)

[삽입정렬](https://www.notion.so/0482368a4c1e419bbd1b68e49d7475a0)

[덱 명령어](https://www.notion.so/66d0c0f502a24f65b48b5ae8c4898e18)

[버블정렬](https://www.notion.so/02d6d4a3523c4c72b1b5aa18fa313840)

[선택정렬](https://www.notion.so/52423fe830844d14a1916226ebff84ab)