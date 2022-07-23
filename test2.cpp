#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define INF 1000000000000000

#define wolvi                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl '\n'


void dfs(int v,vector<int>&vis,vector<vector<int>>&adj,vector<int>&in,vector<int>&out,int &t){

    vis[v]=1;

    in[v]=t++;

    int a = adj[v].size();
    for(int i=0;i<a;i++){
        if(vis[adj[v][i]]==0){
            dfs(adj[v][i],vis,adj,in,out,t);
        }
    }
    out[v]=t++;

}

bool isAncestor(int a,int b,vector<int>&in,vector<int>&out){

    if(in[b]<=in[a] && out[b]>=out[a]){
        return true;
    }
    else return false;

}


int main(){

    wolvi;
    int n,q;
    cin>>n>>q;

    int h=ceil(log2(200000));

    vector<vector<int>>adj(n+1);
    vector<vector<int>>up(n+1,vector<int>(h+1));

    for(int i=1;i<=n;i++){
        int x;cin>>x;
        adj[i].push_back(x);
        up[i][0]=x;
    }

    
    
    for(int j=1;j<=h;j++){
        for(int i=1;i<=n;i++){
            up[i][j] =up[up[i][j-1]][j-1]; 
        }
    }

    vector<int>in(n+1,0);
    vector<int>out(n+1,0);
    vector<int>vis(n+1,0);
    int t=1;
    for(int i=1;i<=n;i++){
        if(vis[i]!=1){
            dfs(i,vis,adj,in,out,t);
        }
    }

    while (q--)
    {
        int a,b;cin>>a>>b;
        swap(a,b);
        if(isAncestor(a,b,in,out)){

            int s=1;
            int e=n; 

            int ans = INT_MAX;    

            while (s<=e)
            {
                int mid = (s+e)/2;
                int k=mid;
                int x = a;
                for(int i=0;i<h;i++){
                    if(k==0)break;
                    if(k&1){
                        x=up[x][i];
                    }
                    k=k>>1;
                }
                cout<<x<<" ";
                if(x==b){
                    ans=min(ans,mid);
                    e=mid-1;
                }
                else{

                    if(isAncestor(x,b,in,out)){
                        s=mid+1;
                    }
                    else e=mid-1;

                }
            }
            
            cout<<ans<<endl;

        }
        else cout<<-1<<endl;
        
    }
    

    //vector<int>vis(n+1,0);



    for(int i=1;i<=n;i++)cout<<in[i]<<" ";
    cout<<endl;

    for(int i=1;i<=n;i++)cout<<out[i]<<" ";
    cout<<endl;

    for(int i=1;i<=n;i++){
        for(int j=0;j<h;j++)cout<<up[i][j]<<" ";
        cout<<endl;
    }




}