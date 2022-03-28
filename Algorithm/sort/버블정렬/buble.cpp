#include<iostream>
using namespace std;
void bubble_sort(int *arr,int arr_len){
  for(int i=arr_len-1;i>=0;i--){
    for(int j=0;j<i;j++){
      if(arr[i]<arr[j]){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
}
int main(){
  int arr[6]={2,9,5,3,8,1};
  bubble_sort(arr,6);
  for(int i=0;i<6;i++){printf("%d ",arr[i]);}
}