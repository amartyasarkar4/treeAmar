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
        bool isBalanced(Node * root){
            return dfsHeight(root)!=-1;
        }
        int dfsHeight(Node * root){
            if(root==NULL){
                return 0;
            }
            int leftHeight=dfsHeight(root->left);
            if(leftHeight==-1){
                return -1;
            }
            int rightHeight=dfsHeight(root->right);
            if(rightHeight==-1){
                return -1;
            }
            cout<<root->data<<": "<<abs(leftHeight-rightHeight)<<endl;
            if(abs(leftHeight-rightHeight)>1){
                return -1;
            }
            return max(leftHeight,rightHeight)+1;
        }
};
int main(){
    struct Node * root=newNode(1);
    root -> left = newNode(2);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(10);
    root -> left -> left -> left = newNode(5);
    root -> left -> left->right = newNode(7);
    // root -> left -> left -> left -> left = newNode(6);
    root -> right = newNode(3);
    root -> right -> left = newNode(9);
    root -> right -> right = newNode(10);
    root->right->right->right=newNode(12);
    root->right->right->left=newNode(17);
    root->right->right->left->right=newNode(19);
    root->right->right->right->left=newNode(22);
    Solution s1;
    bool isBalance=s1.isBalanced(root);


    cout<<"balance "<<isBalance<<endl;
}