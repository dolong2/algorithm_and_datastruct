#include<iostream>
using namespace std;

typedef struct node{
    int data;
    node *right,*left;
}node;
int main(){
    int n;//노드의 수
    cin>>n;
    node nodes[n];
    for(int i=0;i<n;i++){nodes[i].right=NULL;nodes[i].left=NULL;}//초기화
    for(int i=0;i<n;i++){
        int parent,data;//연결될 부모노드와 데이터입력
        if(i==0){
            cin>>data;//scanf("%d",&data);
            nodes[i].data=data;
            continue;//0번째 노드는 연결될 부모노드가 읍따!!
        }
        cin>>parent>>data;
        nodes[parent].right!=NULL?nodes[parent].right=&nodes[i]:nodes[parent].left=&nodes[i];
        nodes[i].data=data;
    }
    for(auto i:nodes){
      cout<<i.data<<endl;
    }//DFS와 BFS를 쓰지 않고 그냥 데이터만 출력
    //DFS와 BFS는 알고리즘 파일에서 구현할거임
}