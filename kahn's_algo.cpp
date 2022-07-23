#include<bits/stdc++.h>
using namespace std;


int main(){

    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);
    vector<int>v(n+1,0);

    while (m--)
    {
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        v[y]++;

    }

    queue<int>q;
    for(int i=1;i<=n;i++){
        if(v[i]==0)q.push(i);
    }
    vector<int>ans;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        ans.push_back(x);

        int a = adj[x].size();
        for(int i=0;i<a;i++){
            v[adj[x][i]]--;
            if(v[adj[x][i]]==0)q.push(adj[x][i]);
        }
    }
    
    if(ans.size()<n)cout<<"IMPOSSIBLE"<<endl;
    else {
        for(int i=0;i<n;i++)cout<<ans[i]<<" ";
        cout<<endl;
    }


    





}