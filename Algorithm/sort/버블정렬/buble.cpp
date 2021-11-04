#include<stdio.h>
void buble_sort(int *arr,int arr_len){
  for(int i=0;i<arr_len;i++){
    for(int j=0;j<arr_len-1;j++){
      if(arr[j]>arr[j+1]){
        int temp=arr[j+1];
        arr[j+1]=arr[j];
        arr[j]=temp;
      }
    }
  }
}
int main(){
  int arr[5]={2,9,5,3,8};
  buble_sort(arr,5);
  for(int i=0;i<5;i++){
    printf("%d ",arr[i]);
  }
}