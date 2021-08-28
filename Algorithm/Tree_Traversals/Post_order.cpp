#include<iostream>
using namespace std;

void Postorder(node *node){
    Postorder(node->left);
    Postorder(node->right);
    cout<<node->data<<" ";
}
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
        nodes[parent].left==NULL?nodes[parent].left=&nodes[i]:nodes[parent].right=&nodes[i];
        nodes[i].data=data;
    }
    Postorder(&nodes[0]);
}