#include <bits/stdc++.h>

using namespace std;

void heapify( vector<int>&arr,int i,int n){

    if(i>=n)return;
    
    int l = 2*i+1;
    int r = 2*i+2;

    int temp=i;

    if(l<n && arr[temp]>arr[l])temp=l;
    if(r<n && arr[temp]>arr[r])temp=r;

    swap(arr[temp],arr[i]);

    if(temp!=i)heapify(arr,temp,n);

}

void heapsort(vector<int>&arr,int n){

    int x = n;
    while (x>1)
    {
        swap(arr[0],arr[x-1]);
        x--;
        heapify(arr,0,x);
    }

}

int main(){

    int n;cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++)cin>>arr[i];

    for(int i=n/2-1;i>=0;i--)heapify(arr,i,n);

    heapsort(arr,n);

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";



}