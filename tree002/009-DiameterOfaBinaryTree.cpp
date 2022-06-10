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
        int diameterOfBinaryTree(Node * root){
            int diameter=0;
            totalHeightlhPlusRh(root,diameter);
            return diameter;
        }
    private:
        int totalHeightlhPlusRh(Node * root,int &diameter){
            if(!root){
                return 0;
            }
            int lh=totalHeightlhPlusRh(root->left,diameter);
            int rh=totalHeightlhPlusRh(root->right,diameter);

            diameter=max(diameter,lh+rh);
            cout<<"root:"<<root->data<<"diameter : "<<lh<<" "<<rh<<endl;
            return (max(lh,rh)+1);
        }
};
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
    Solution s1;
    int maxWidthOfBinaryTree=s1.diameterOfBinaryTree(root);


    cout<<"Maximum width(diameter) of this Binary tree is: "<<maxWidthOfBinaryTree<<endl;
}