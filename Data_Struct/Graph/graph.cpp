#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> graph[1001];
    int n;
    cin>>n;//몇개의 노드가 있는지 입력
    for(int i=0;i<n;i++){
        int parent,child;
        cin>>parent>>child;
        graph[parent].push_back(child);
        graph[child].push_back(parent);
    }
}