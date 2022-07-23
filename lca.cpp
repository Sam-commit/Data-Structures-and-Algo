#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>adj(100001);


int main(){


    int n,m;cin>>n>>m;
    while (m--)
    {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<vector<int>>
    



}