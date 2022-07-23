#include <bits/stdc++.h>
using namespace std;


int solve(int i,int j,int z,int m,int s[]){

    if(i>j && z==0)return 1;
    if(z<0)return 0;
    if(i>j)return 0;
    if(s[i]%2)return 0;


    int ans = 0;
    int cnt=1;
    for(int k=i;k<=j;k++){
        if(s[k]%2 && cnt>=m){
            ans+=solve(k+1,j,z-1,m,s);
        }
        cnt++;
    }

    return ans;


}

int main(){

    int n,m,k;cin>>n>>m>>k;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<solve(0,n-1,k,m,arr);
    return 0;


}