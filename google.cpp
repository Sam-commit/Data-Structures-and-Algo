#include<bits/stdc++.h>
using namespace std;

int ans=0;
map<int,int>mp;

void dfs(int v,int p,vector<vector<int>>&adj,int arr[],int x,int freq){


    int y = x/2;
    if(x%2)y++;

    //cout<<cnt<<" "<<y<<endl;

    if(freq>=y)ans++;

    int a = adj[v].size();
    for(int i=0;i<a;i++){
        if(adj[v][i]!=p){
            mp[adj[v][i]]++;
            if(mp[adj[v][i]]>freq)freq = mp[adj[v][i]];
            dfs(adj[v][i],v,adj,arr,x+1,freq);
            mp[adj[v][i]]--;
        }
    }

}


int main(){

    int n;cin>>n;
    int arr[n+1];
    for(int i=1;i<=n;i++)cin>>arr[i];
    vector<vector<int>>adj(n+1);

    for(int i=0;i<n-1;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    map<int,int>mp;
    mp[1]++;
    dfs(1,1,adj,arr,1,1);

    cout<<ans;

    return 0;



}