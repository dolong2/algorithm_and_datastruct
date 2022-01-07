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

- [**리스트(List)**](./Data_Struct/List/List.md)

- [**유클리드 알고리즘**](./Algorithm/euclid/euclid.md)

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