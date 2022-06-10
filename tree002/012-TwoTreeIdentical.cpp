#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    struct TreeNode * left;
    struct TreeNode * right;
};
struct TreeNode * newTnode(int val){
    struct TreeNode * myTnode=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    myTnode->left=NULL;
    myTnode->right=NULL;
    return myTnode;
}
bool isIdentical(struct TreeNode * t1,struct TreeNode *t2){
    if(t1==NULL && t2 ==NULL){
        return true;
    }
    if(t1==NULL||t2==NULL){
        return false;
    }
    return t1->data==t2->data && isIdentical(t1->left,t2->left)&& isIdentical(t1->right,t2->right);
}
int main(){
    struct TreeNode * root1 = newTnode(1);
    root1 -> left = newTnode(2);
    root1 -> right = newTnode(3);
    root1 -> right -> left = newTnode(4);
    root1 -> right -> right = newTnode(5);

    struct TreeNode * root2 = newTnode(1);
    root2 -> left = newTnode(2);
    root2 -> right = newTnode(3);
    root2 -> right -> left = newTnode(4);
    // root2 -> right -> right = newTnode(5);

    if(isIdentical(root1,root2)){
        cout<<"Two Trees are Identical."<<endl;
    }else{
        cout<<"two trees are Non-Identical."<<endl;
    }
}