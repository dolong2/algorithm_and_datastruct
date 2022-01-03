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