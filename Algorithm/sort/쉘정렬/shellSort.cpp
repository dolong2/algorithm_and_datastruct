#include<iostream>
using namespace std;
void gap_sort(int arr[],int size){
	for(int i=size/2;i>0;i/=2){
		if(i%2==0){
			i++;
		}
		for(int j=0;j<i;j++){
			insertInsection(arr,j,size-1,i);
		}
	}
}
void insertInsection(int arr[],int start,int last,int gap){
	for (i = start+ gap; i <= last; i += gap){
    int key = list[i];
    for (j = i - gap; j >= start&& list[j] > key; j -= gap){
      list[j + gap] = list[j];
    }
    list[j + gap] = key;
	}
}
int main(){
	int arr[10];
	for(int i=0;i<10;i++){
		cin>>arr[i];
	}
	gap_sort(arr,10);
	for(int i=0;i<10;i++){
		cout>>arr[i]<<" ";
	}
}