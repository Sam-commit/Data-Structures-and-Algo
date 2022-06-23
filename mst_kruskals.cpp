#include <bits/stdc++.h>
using namespace std;


int findParent(int u,vector<int>&parent){

    if(parent[u]==u)return u;
    return parent[u] = findParent(parent[u],parent); 
}

void unionSet(int u,int v,vector<int>&parent,vector<int>&rank){

    if(rank[u]>rank[v]){
        parent[v]=u;
    }
    else if(rank[u]<rank[v]){
        parent[u] = v;
    }
    else {
        parent[u]=v;
        rank[v]++;
    }
}


int main (){

    int n,m;

    vector<pair<int,pair<int,int>>>edges;

    for(int i=0;i<m;i++){
        int x,y,w;cin>>x>>y>>w;
        edges.push_back({w,{x,y}});
    }

    sort(edges.begin(),edges.end());

    vector<int>parent(n);
    vector<int>rank(n,0);

    for(int i=0;i<n;i++)parent[i]=i;

    int ans=0;

    for(int i=0;i<edges.size();i++){

        int v = edges[i].second.first;
        int u = edges[i].second.second;

        v = findParent(v,parent);
        u = findParent(u,parent);

        if(v!=u){
            ans+=edges[i].first;
            unionSet(v,u,parent,rank);
        }

    }




}