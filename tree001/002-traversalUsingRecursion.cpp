#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};

struct Node * newNode(int data){
    struct Node * Node=(struct Node *)malloc(sizeof(struct Node));
    Node->data=data;
    Node->left=NULL;
    Node->right=NULL;
    return (Node); 
}
void preOrderTrav(struct Node * curr,vector<int>&preOrder){
    if(curr==NULL){
        return;
    }
    preOrder.push_back(curr->data);
    preOrderTrav(curr->left,preOrder);
    preOrderTrav(curr->right,preOrder);
}
void inOrderTrav(struct Node * curr,vector<int>&inOrder){
    if(curr==NULL){
        return;
    }
    inOrderTrav(curr->left,inOrder);
    inOrder.push_back(curr->data);
    inOrderTrav(curr->right,inOrder);
}
void postOrderTrav(struct Node * curr,vector<int>&postOrder){
    if(curr==NULL){
        return;
    }
    postOrderTrav(curr->left,postOrder);
    postOrderTrav(curr->right,postOrder);
    postOrder.push_back(curr->data);
}

int main(){
    struct Node * root = newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> left -> right -> left = newNode(8);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);
    root -> right -> right -> left = newNode(9);
    root -> right -> right -> right = newNode(10);
    vector<int>preOrder;
    preOrderTrav(root,preOrder);
    cout<<"The PreOrder Traversal is: ";
    for(int i=0;i<preOrder.size();i++){
        cout<<preOrder[i]<<"-";
    }
    cout<<endl;

    vector<int>inOrder;
    inOrderTrav(root,inOrder);
    cout<<"The In-Order Traversal is: ";
    for(int i=0;i<inOrder.size();i++){
        cout<<inOrder[i]<<"-";
    }
    cout<<'\n';
    vector<int>postOrder;
    postOrderTrav(root,postOrder);

    cout<<"The PostOrder Traversal is: ";
    for(int i=0;i<postOrder.size();i++){
        cout<<postOrder[i]<<" ";
    }
}