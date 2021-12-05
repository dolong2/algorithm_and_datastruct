<h1>자료구조 & 알고리즘</h1>

- **빅오표기법**
    - 알고리즘의 효율도를 분석하는 방법
    - **기본적으로, 알고리즘 최악의 경우의 복잡도를 측정**
    - 표기: ex)O(n),O(log n),O(1)

- [**스택**](Data_Struct/stack/stack.md)
    

- **큐**
    - 스택과 유사하지만 FIFO(First In First Out)방식을 사용한다
    - 접근이 스택의 앞과 뒤에서 일어남
    - 큐 구조
    
    ![queue.gif](./img/queue.gif)
    
    - [명령어](https://www.notion.so/941794de4b0248cfaeb68b08181d03a7)
    - 구현(c)
    
    ```c
    #include<stdio.h>
    #include<string.h>
    typedef struct queue{
      int front;
      int back;
      int arr[100000];
    }queue;
    int size(queue *que){
      return que->back-que->front;
    }
    int empty(queue *que){
      if(size(que)!=0)return 0;
      else return 1;
    }
    void push(queue *que,int n){
      que->arr[que->back++]=n;
    }
    void pop(queue *que){
      if(!empty(que))
        printf("%d\n",que->arr[que->front++]);
      else
        printf("-1\n");
    }
    void front(queue *que){
      if(!empty(que))
        printf("%d\n",que->arr[que->front]);
      else
        printf("-1\n");
    }
    void back(queue *que){
      if(!empty(que))
        printf("%d\n",que->arr[que->back-1]);
      else
        printf("-1\n");
    }
    int main(){
        queue que;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
          char order[6];
          scanf("%s",order);
          if(!strcmp(order,"push")){
            int n;
            scanf("%d",&n);
            push(&que,n);
          }
          else if(!strcmp(order,"pop"))
            pop(&que);
          else if(!strcmp(order,"size"))
            printf("%d\n",size(&que));
          else if(!strcmp(order,"empty"))
            printf("%d\n",empty(&que));
          else if(!strcmp(order,"front"))
            front(&que);
          else if(!strcmp(order,"back"))
            back(&que);
        }
    }
    ```
    

- **덱(dequeue)**
    - 스택과 큐를 합친 느낌의 자료구조
    - 앞과 뒤에서 접근이 일어날 수 있음
    - 검색하지 않을 때 사용하기 용이함
    - 데이터 접근을 앞 뒤에서 다 할 수 있어서 접근을 무작위로 하고 싶을 때 용이함
    - 구현을 연결 리스트로 할 수 있음
    - 데큐 구조
    
    ![dequeue.gif](./img/dequeue.gif)
    
    - [명령어](https://www.notion.so/66d0c0f502a24f65b48b5ae8c4898e18)
    - 구현(c)
    
    ```cpp
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
    ```
    

- **서치(알고리즘)**
    - [선형서치(Linear Search)](https://www.notion.so/596715d04a104c52a6193e258fc07908)
    - [이진서치(Binary Search)](https://www.notion.so/c8b7a6fc4bd24627969c4ad99f09d99c)

- **정렬(알고리즘)**
    - [선택정렬](https://www.notion.so/52423fe830844d14a1916226ebff84ab)
    - [삽입정렬](https://www.notion.so/0482368a4c1e419bbd1b68e49d7475a0)
    - [버블정렬](https://www.notion.so/02d6d4a3523c4c72b1b5aa18fa313840)
    - 퀵정렬
    - 합병정렬
    - [쉘정렬](https://www.notion.so/f1c6aabaf8c24a308179a2f0baff5fac)

- **그래프(Graph)**
    
    그래프는 vertex와 edge로 구성된 한정된 자료구조임
    
    ### 용어
    
    - 정점(vertex)
        
        노드(node)라고도 부르며 데이터가 저장되는 지점
        
    - 간선(edge)
        
        링크(arcs)라고도 부르며 정점들을 연결 시켜주는 역할
        
    
    ### 구현 방법
    
    - **인접 리스트**
        
        그래프의 노드들을 리스트로 표현한 것
        
        정점의 리스트 배열을 만들어 관계를 설정해서 구현한다'
        
        ### 장점
        
        - 정점들의 연결 정보를 탐색하는데 O[n]의 시간 복잡도를 가진다
        - 필요한 만큼의 공간만 사용하기 때문에 공간의 낭비가 적다
        
        ### 단점
        
        - 특정 두 점이 연결되었는지 확인하려면 인접 행렬 보다 시간이 오래 걸린다
        - 구현이 비교적 어렵다
    - **인접 행렬**
        
        그래프의 정점을 2차원 배열로 구현한 
        
        정점을 연결하는 정점에 대해서 인접 정점이라면 1을 아니라면 0을 삽입한다
        
        ### 장점
        
        - 2차원 배열에 모든 간선에 정보를 담아서 배열의 위치를 확인하면 두 점에 대한 정보를 조회할 때 O[1]의 시간 복잡도를 가진다.
        - 구현이 비교적 간단하다
        
          
        
        ### 단점
        
        - 모든 정점에 대해서 정보를 대입해야 해서 O[n^2]의 시간 복잡도를 가진다
        - 무조건 2차원 배열로 구현하므로 필요 이상의 공간이 필요하다
    
    ### 탐색 방법
    
    - **DFS**(깊이 우선 탐색)
        
        ![DFS](./img/dfs.gif)
        
        그래프를 갈 수 있는 만큼 깊이 가고
        
        더 이상 갈 수 없을 때 이전 정점으로 돌아가는 방식을 사용함
        
        주로 재귀 함수나 스택으로 구현함
        
    - **BFS**(넓이 우선 탐색)
        
        ![BFS](./img/bfs.gif)
        
        시작 정점을 방문하고 시작 정점에 인접한 모든 정점을 방문하는 방식
        
        일반적으로 큐로 구현함
        

- **트리(tree)**
    
    그래프의 일종으로, 여러 노드가 한 노드를 가리킬 수 없는 구조이다. 서로 다른 두 노드를 잇는 길이 하나뿐인 그래프를 트리라고 부른다.
    
    ### 용어
    
    - 노드(node)
        
        트리의 데이터가 저장되는 각 지점
        
    - 간선(edge)
        
        노드들을 연결하는 선
        
    
    ### 종류
    
    - 이진트리
        
        자식 노드가 2개밖에 없는 트리(모든 트리가 이진 트리는 아님)
        
        - 이진 탐색 트리
            
            모든 노드가 특정 순서를 따르는 속성이 있는 이진 트리
            
    
    ### 이진 트리 구현 방법
    
    ```cpp
    #include<iostream>
    using namespace std;
    class Tree {
    public:
        int data;
        Tree* left, * right;
    };
    int main() {
        int n;
        cin >> n;
        Tree tree[101];//n이 100보다 작다
        for (int i = 1; i <= n+1;i++) {
            tree[i].data = 0;
            tree[i].left = nullptr;
            tree[i].right = nullptr;
        }
        tree[1].data = 1;
        for (int i = 0; i < n; i++) {
            int x, y;//x 부모,y 자식
            cin >> x >> y;
            tree[y].data = y;
            tree[x].left == nullptr ? tree[x].left = &tree[y] : tree[x].right = &tree[y];
        }
    }
    ```
    
    ### 탐색
    
    - 전위 순회(PreOrder)
        
        현재 노드→왼쪽 노드→오른쪽 노드
        
        ```cpp
        #include<iostream>
        using namespace std;
        class Tree {
        public:
            int data;
            Tree* left, * right;
        };
        void preOrder(Tree* tree) {
            if (tree != NULL) {
                cout << tree->data << endl;
                preOrder(tree->left);
                preOrder(tree->right);
            }
        }
        int main() {
            int n;
            cin >> n;
            Tree tree[101];//n이 100보다 작다
            for (int i = 1; i <= n+1;i++) {
                tree[i].data = 0;
                tree[i].left = nullptr;
                tree[i].right = nullptr;
            }
            tree[1].data = 1;
            for (int i = 0; i < n; i++) {
                int x, y;//x 부모,y 자식
                cin >> x >> y;
                tree[y].data = y;
                tree[x].left == nullptr ? tree[x].left = &tree[y] : tree[x].right = &tree[y];
            }
            preOrder(&tree[1]);
        }
        ```
        
    - 중위 순회(InOrder)
        
        왼쪽 노드→현재 노드→오른쪽 노드
        
        ```cpp
        #include<iostream>
        using namespace std;
        class Tree {
        public:
            int data;
            Tree* left, * right;
        };
        void InOrder(Tree* tree) {
            if (tree != NULL) {
                InOrder(tree->left);
                cout << tree->data << endl;
                InOrder(tree->right);
            }
        }
        int main() {
            int n;
            cin >> n;
            Tree tree[101];//n이 100보다 작다
            for (int i = 1; i <= n+1;i++) {
                tree[i].data = 0;
                tree[i].left = nullptr;
                tree[i].right = nullptr;
            }
            tree[1].data = 1;
            for (int i = 0; i < n; i++) {
                int x, y;//x 부모,y 자식
                cin >> x >> y;
                tree[y].data = y;
                tree[x].left == nullptr ? tree[x].left = &tree[y] : tree[x].right = &tree[y];
            }
            InOrder(&tree[1]);
        }
        ```
        
    - 후위 순회(PostOrder)
        
        왼쪽 노드→오른쪽 노드→현재 노드
        
        ```cpp
        #include<iostream>
        using namespace std;
        class Tree {
        public:
            int data;
            Tree* left, * right;
        };
        void PostOrder(Tree* tree) {
            if (tree != NULL) {
                PostOrder(tree->left);
                PostOrder(tree->right);
        				cout << tree->data << endl;
            }
        }
        int main() {
            int n;
            cin >> n;
            Tree tree[101];//n이 100보다 작다
            for (int i = 1; i <= n+1;i++) {
                tree[i].data = 0;
                tree[i].left = nullptr;
                tree[i].right = nullptr;
            }
            tree[1].data = 1;
            for (int i = 0; i < n; i++) {
                int x, y;//x 부모,y 자식
                cin >> x >> y;
                tree[y].data = y;
                tree[x].left == nullptr ? tree[x].left = &tree[y] : tree[x].right = &tree[y];
            }
            PostOrder(&tree[1]);
        }
        ```
        

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