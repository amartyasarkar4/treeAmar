#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * newNode(int val){
    struct Node * myNode=(struct Node *)malloc(sizeof(struct Node));
    myNode->data=val;
    myNode->left=NULL;
    myNode->right=NULL;
    return myNode;
}
int maxHeight(Node * root){
    if(!root){
        return 0;
    }
    int leftHeight=maxHeight(root->left);
    int rightHeight=maxHeight(root->right);

    return (max(leftHeight,rightHeight)+1);
}
int main(){
    struct Node * root=newNode(1);
    root -> left = newNode(2);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(10);
    root -> left -> left -> right = newNode(5);
    root -> left -> left -> right -> right = newNode(6);
    root -> right = newNode(3);
    root -> right -> left = newNode(9);
    root -> right -> right = newNode(10);

    int maxheightOfBinaryTree=maxHeight(root);

    cout<<"Maximum height of this Binary tree is: "<<maxheightOfBinaryTree<<endl;
}