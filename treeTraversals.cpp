#include <bits/stdc++.h>
using namespace std;

class node {

    public:
        int data;
        node* left;
        node* right;

        node(int x){
            this->data = x;
            this -> left = NULL;
            this -> right = NULL;  
        }
};

node* buildTree(node* root) {

    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;

}

node* inorderTraversal(node* root){

    if(root == NULL )return;

    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);


}

void preorder(node* root) {
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root) {

    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}


int main(){

    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];

    node* root = NULL; 
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    





    return 0;
}