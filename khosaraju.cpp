#include<bits/stdc++.h>
using namespace std;

#define int long long


void dfs(int v,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st){



    vis[v]=1;
    int a = adj[v].size();

    for(int i=0;i<a;i++){

        if(vis[adj[v][i]]!=1){
            dfs(adj[v][i],adj,vis,st);
        }

    }

    st.push(v);

}

void dfs2(int v,vector<vector<int>>&adj,vector<int>&vis){



    vis[v]=1;
    int a = adj[v].size();

    for(int i=0;i<a;i++){

        if(vis[adj[v][i]]!=1){
            dfs2(adj[v][i],adj,vis);
        }

    }


}

signed main(){

    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n+1);    

    stack<int>st;

    for(int i=0;i<m;i++){

        int x,y;cin>>x>>y;
        adj[x].push_back(y);

    }

    vector<int>vis(n+1,0);

    for(int i=1;i<=n;i++){
        if(vis[i]!=1){
            dfs(i,adj,vis,st);
        }
    }

    vector<vector<int>>trans(n+1);

    for(int i=1;i<=n;i++){
        vis[i]=0;
        int a = adj[i].size();
        for(int j=0;j<a;j++){
            trans[adj[i][j]].push_back(i);
        }

    }

    int cnt =0;
    int temp =-1;

    while (!st.empty())
    {
        int x = st.top();
        st.pop();

        if(vis[x]!=1){
            cnt++;
            if(cnt==2){
                cout<<"NO"<<endl;
                cout<<x<<" "<<temp<<endl;
                return 0;
            }
            temp = x;
            dfs2(x,trans,vis);
        }


    }

    cout<<"YES"<<endl;
     



    // vector<int>v;
    // while (!st.empty())
    // {
        
    //     int x = st.top();
    //     st.pop();
    //     vis[x]=0;
    //     v.push_back(x); 

    // }

    // int cnt =0;
    // int temp = -1;

    // for(int i=n-1;i>=0;i--){

    //     if(vis[v[i]]!=1){
    //         cnt++;
    //         if(cnt==2){

    //             cout<<"NO"<<endl;
    //             cout<<temp<<" "<<v[i]<<endl;
    //             return 0;

    //         }
    //         temp = v[i];
    //         dfs(v[i],adj,vis,st);
    //     }

    // }
    

    // cout<<"YES"<<endl;

    
    return 0;

}