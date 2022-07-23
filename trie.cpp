#include<bits/stdc++.h>
using namespace std;


struct TrieNode{
    
    char c;
    TrieNode* children[26];
    bool isTerminal;
        
    TrieNode(char value){
        c = value;
        for(int i=0;i<26;i++)children[i]=NULL;
        isTerminal = false;
    }
    
};

void insertData(string a,TrieNode* root){
    
    //cout<<a<<" ";
    
    if(a.length()==0){
        root->isTerminal = true;
        return;
    }
    
    if(root->children[a[0]-'a']!=NULL){
        insertData(a.substr(1),root->children[a[0]-'a']);
    }
    else {
        
        TrieNode* node = new TrieNode(a[0]);
        root->children[a[0]-'a'] = node;
        insertData(a.substr(1),root->children[a[0]-'a']);
        
    }
}

int check(string a,TrieNode* node){

    cout<<a<<" ";
    
    if(a.length()==0){
        if(node->isTerminal)
        return 1;
        else return 0;
    }
    
    if(node->children[a[0]-'a']!=NULL){
        return check(a.substr(1),node->children[a[0]-'a']);
    }
    else {
        return 0;
    }
    
}

int main(){

    string A;cin>>A;
    int n; cin>>n;
    vector<string>B(n);

    for(int i=0;i<n;i++)cin>>B[i];

 TrieNode* root = new TrieNode('1');
    string temp="";
    for(int i=0;i<A.length();i++){
        
        if(A[i]=='_'){
            insertData(temp,root);
            temp = "";
        }
        else temp+=A[i];
        
    }
    insertData(temp,root);
    
    vector<pair<int,int>>v;
        
    for(int i=0;i<B.size();i++){
        
        string temp="";
        int x = 0;
        for(int j=0;j<B[i].length();j++){
        
            if(B[i][j]=='_'){
                x+=check(temp,root);
                temp = "";
            }
            else temp+=B[i][j];
        
        }
        x+=check(temp,root);
         cout<<x<<" ";
        v.push_back({x,i});
    }
    
    sort(v.begin(),v.end(),greater<pair<int,int>>());
    
    vector<int>ans;
    
    for(int i=0;i<v.size();i++)ans.push_back(v[i].second);
    
    //return ans;
    
    for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;



}
