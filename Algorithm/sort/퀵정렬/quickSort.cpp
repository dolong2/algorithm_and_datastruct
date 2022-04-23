#include<iostream>
#include <algorithm>

using namespace std;

void quickSort(int A[], int low, int high) {
    if(low >= high) return;

    int i = low, j = low;
    int&pivot = A[high];
    for (; j < high; ++j) {
        if ( A[j] < pivot)
            swap(A[i++], A[j]);
    }
    swap(A[i], pivot);

    quickSort(A, low, i-1);
    quickSort(A, i+1, high);
}

int main(){
  int arr[5] = {5,6,1,2,9};
  quickSort(arr, 0, 4);
  for(auto i : arr){
    cout<<i<<" ";
  }
  cout<<endl;
}