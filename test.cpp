#include<bits/stdc++.h>
using namespace std;


vector<vector<int>>adj(26);
vector<int>vis(26,0);
int n;
bool flag=false;
vector<int>ans;

void dfs(int v){

    //cout<<v<<endl;
    int a = adj[v].size();
    if(a==0)return;
    vis[v]=1;

    for(int i=0;i<a;i++){
        if(vis[adj[v][i]]==1){
            flag=true;
        }
        else if(vis[adj[v][i]]!=2){
            dfs(adj[v][i]);
        }
    }
    //cout<<v<<endl;
    vis[v]=2;
    ans.push_back(v);
    
}

int main(){

    cin>>n;
    vector<string>v(n);
    vector<int>root;
    for(int i=0;i<n;i++)cin>>v[i];
    
    map<int,int>m;

    for(int i=1;i<n;i++){

        string a = v[i-1];
        string b = v[i];

        int j=0;

        while (j<a.length() && j<b.length())
        {
            if(a[j]!=b[j]){

                char x = a[j];
                char y = b[j];

                if(m[x-'a']==0 && m[y-'a']==0){
                    root.push_back(x-'a');
                }
                m[x-'a']=1;
                m[y-'a']=1;
                adj[x-'a'].push_back(y-'a');
                
                break;
            }
            j++;
        }
    }
    for(int i=0;i<root.size();i++)
    dfs(root[i]);

    if(flag){
        cout<<"Impossible"<<endl;
    }
    else {
        
        reverse(ans.begin(),ans.end());
        string aa="";
        map<char,int>mp;
        for(int i=0;i<ans.size();i++){
           //cout<<ans[i]+97<<endl;
            aa+=ans[i]+97;
            mp[ans[i]+97]=1;
        }

        for(int i=0;i<26;i++){
            if(mp[i+97]!=1){
                aa+=i+97;
            }
        }

        cout<<aa<<endl;



    }





}