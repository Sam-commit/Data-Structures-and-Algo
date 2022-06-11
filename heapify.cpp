#include <bits/stdc++.h>

using namespace std;

void solve(int arr[],int i,int n){

    if(i>=n)return;
    
    int l = 2*i+1;
    int r = 2*i+2;

    int temp=i;

    if(l<n && arr[temp]>arr[l])temp=l;
    if(r<n && arr[temp]>arr[r])temp=r;

    swap(arr[temp],arr[i]);

    if(temp!=i)solve(arr,temp,n);

}


int main(){

    int arr[5] = {5,3,4,6,7};   

    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=n/2;i>=0;i--)solve(arr,i,n);

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";


}