#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void dfs(int v,int p,vector<int>&vis,vector<int>&dis,vector<int>&low,vector<vector<int>>&adj,int &timer){

    vis[v]=1;
    dis[v]=low[v]=timer++;

    int a = adj[v].size();

    for(int i=0;i<a;i++){

        if(adj[v][i]==p)continue;

        if(!vis[adj[v][i]]){
            dfs(adj[v][i],v,vis,dis,low,adj,timer);

            low[v] = min(low[v],low[adj[v][i]]);
            if(low[adj[v][i]]>dis[v])ans++;

        }

        if(vis[adj[v][i]] && adj[v][i]!=p){
            low[v] = min(dis[adj[v][i]],low[v]);
        }
    }

}

int main(){

    int n,m;cin>>n>>m;

    vector<vector<int>>adj(n+1);

    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int>dis(n+1,-1);
    vector<int>vis(n+1,0);
    vector<int>low(n+1,-1);
    int timer =0;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,-1,vis,dis,low,adj,timer);
        }
    }





}