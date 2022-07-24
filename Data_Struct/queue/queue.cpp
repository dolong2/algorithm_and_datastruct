#include<iostream>
#include<string.h>
using namespace std;
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
    cin>>n;
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