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
class Solution{
    public:
        Node * lowestCommonAncestor(Node * root,Node *p,Node * q){
            if(root==NULL||root==p||root==q){
                return root;
            }
            Node * left=lowestCommonAncestor(root->left,p,q);
            Node * right=lowestCommonAncestor(root->right,p,q);

            if(left==NULL){
                return right;
            }else if(right==NULL){
                return left;
            }else{
                return root;
            }
        }
        Node * lowestCommonAncestorByVal(Node * root,int vp,int vq){
            if(root==NULL||root->data==vp||root->data==vq){
                return root;
            }
            Node * left=lowestCommonAncestorByVal(root->left,vp,vq);
            Node * right=lowestCommonAncestorByVal(root->right,vp,vq);

            if(left==NULL){
                return right;
            }else if(right==NULL){
                return left;
            }else{
                return root;
            }
        }
};
int main(){
    struct Node * root=newNode(1);
    root -> left = newNode(2);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(10);
    root -> left -> left -> left = newNode(5);
    root -> left -> left -> left -> left = newNode(6);
    root -> right = newNode(3);
    root -> right -> left = newNode(9);
    root -> right -> right = newNode(8);

    Solution s1;
    Node * LCA=s1.lowestCommonAncestor(root,root -> left -> left -> left,root -> left -> right);

    cout<<LCA->data<<endl;

    Node * LCA2=s1.lowestCommonAncestorByVal(root,8,10);
    cout<<LCA2->data<<endl;
}