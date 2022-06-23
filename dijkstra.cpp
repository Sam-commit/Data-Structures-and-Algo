#include<bits/stdc++.h>
using namespace std;






int main(){


    int n,m;
    vector<vector<pair<int,int>>>adj(n+1);

    while (m--)
    {
        int x,y,w;cin>>x>>y>>w;
        adj[x].push_back({y,w});
        adj[y].push_back({x,w});
    }

    vector<int>dist(n+1);
    for(int i=0;i<=n;i++)dist[i] = INT_MAX;

    dist[1]=0;
    priority_queue<pair<int,int>>pq;
    vector<int>vis(n+1,0);
    pq.push({0,1});

    while (!pq.empty())
    {

        pair<int,int>node = pq.top();
        pq.pop();

        int v = node.second;
        int w = node.first;
        vis[v]=1;

        int a = adj[v].size();
        for(int i=0;i<a;i++){

            if(vis[adj[v][i].first]==0){
                if(dist[v] + adj[v][i].second<dist[adj[v][i].first]){
                    dist[adj[v][i].first] = dist[v] + adj[v][i].second;
                    pq.push({dist[adj[v][i].first],adj[v][i].first});
                }
            }

        }
    }


}