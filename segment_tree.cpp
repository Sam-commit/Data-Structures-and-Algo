#include<bits/stdc++.h>
using namespace std;

void buildSegmentTree(int ind,int low,int high,int arr[],int seg[]){

    if(low==high){
        seg[ind] = arr[low];
        return;
    }

    int mid = (low+high)/2;
    buildSegmentTree(2*ind+1,low,mid,arr,seg);
    buildSegmentTree(2*ind+2,mid+1,high,arr,seg);
    seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);


}

int querySGT(int ind,int l,int r,int low,int high,int seg[]){

    if(l>high || r<low)return INT_MAX;

    if(l<=low && high<=r)return seg[ind];

    int mid = (low+high)/2;
    int t1 = querySGT(2*ind+1,l,r,low,mid,seg);
    int t2 = querySGT(2*ind+2,l,r,mid+1,high,seg);

    return min(t1,t2);

}


int main(){

    int n;cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)cin>>arr[i];

    int seg[4*n+1];
    buildSegmentTree(0,0,n-1,arr,seg);

    int q;cin>>q;

    while (q--)
    {
        int l,r;cin>>l>>r;

    }
    




}