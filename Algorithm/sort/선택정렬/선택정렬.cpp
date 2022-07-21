#include<iostream>
using namespace std;
void selection_sort(int *arr,int arr_len){
  for(int i=0;i<arr_len;i++){
    int min=1000,min_index;
    for(int j=i;j<arr_len;j++){
      if(min>arr[j]){
        min=arr[j];
        min_index=j;
      }
    }
    int temp=arr[i];
    arr[i]=min;
    arr[min_index]=temp;
  }
}
int main(){
  int arr[5]={2,9,5,3,8};
  selection_sort(arr,5);
  for(int i=0;i<5;i++){
    cout<<arr[i]<<" ";
  }
}