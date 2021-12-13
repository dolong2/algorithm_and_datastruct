#include<iostream>
#include<algorithm>
using namespace std;
int arr[10]={0,1,2,3,4,5,6,7,8,9};//0~9사이의 숫자가 들어있는 배열
int binary_search(int n){
    int start=0,end=9,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(arr[mid]==n)return mid;
        else if(arr[mid]>n)end=mid-1;
        else start=mid+1;
    }
    return -1;
}//찾은 수의 인덱스를 반환 없으면 -1을 반환
int main(){
    int n;//배열안에서 찾을 숫자
    cin>>n;
    cout<<binary_search(n);
}