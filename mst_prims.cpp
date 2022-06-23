#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    vector<vector<pair<int,int>>>adj(n);

    for(int i=0;i<m;i++){
        int x,y,w;cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    vector<int>parent(n,-1);
    vector<int>dist(n,INT_MAX);
    vector<int>vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

    pq.push({0,0});

    while (!pq.empty())
    {
        pair<int,int>node = pq.top();
        pq.pop();

        int v = node.second;
        int w = node.first;
        vis[v]=1;

        int a = adj[v].size();
        for(int i=0;i<a;i++){
            if(vis[adj[v][i].first]!=1){

                int wt = adj[v][i].second;
                if(wt<dist[adj[v][i].first]){
                    dist[adj[v][i].first]=wt;
                    parent[adj[v][i].first]=v;
                    pq.push({adj[v][i].second,adj[v][i].first});
                }

            }
        }
    }

    vector<pair<pair<int,int>,int>>ans;
    for(int i=0;i<n;i++){

        if(parent[i]!=-1){
            ans.push_back({{parent[i],i},dist[i]});
        }

    }



}