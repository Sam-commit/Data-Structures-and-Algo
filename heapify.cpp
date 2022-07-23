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

void insert(int x,vector<int>&arr){


    arr.push_back(x);
    int y = arr.size()-1;
    int p = (y-1)/2;

    while(p>0 && arr[p]>arr[y]){
        swap(arr[p],arr[y]);
        y = p;
        //if(y==0)break;
        p = (y-1)/2;
    }

}

void delroot(vector<int>&arr){

    int n = arr.size();
    arr[0] = arr[n-1];
    n--;

    heapify(arr,0,n);

}

void delany(int x,vector<int>&arr,int n){

    int i = search(x,arr,n);

    arr[i] = INT32_MIN;
    int p = (i-1)/2;

    while(p>=0 && arr[p]>arr[i]){

        swap(arr[i],arr[p]);
        i=p;
        p = (i-1)/2;

    }

    delroot(arr);

}

int search(int x,vector<int>&arr,int n){

    for(int i=0;i<n;i++){
        if(arr[i]==x)return i;        
    }

}



int main(){

    vector<int>arr{5,3,4,6,7};   

    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=n/2;i>=0;i--)heapify(arr,i,n);

    for(int i=0;i<n;i++)cout<<arr[i]<<" ";


}