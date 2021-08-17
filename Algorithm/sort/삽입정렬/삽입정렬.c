#include<stdio.h>
void intsertion_sort(int arr[],int n){
  int key,j;
  for(int i=1;i<n;i++){
    key=arr[i];
    for(j=i-1;j>=0&&arr[j]>key;j--){
      arr[j+1]=arr[j];
    }
    arr[j+1]=key;
  }
}
int main(){
  int arr[10]={3,9,2,1,8,5,7,6,4,10};
  intsertion_sort(arr,10);
  for(int i=0;i<10;i++)printf("%d ",arr[i]);
}