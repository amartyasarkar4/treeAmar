#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * newNode(int val){
    struct Node * myNode=new Node;
    myNode->data=val;
    myNode->left=NULL;
    myNode->right=NULL;

    return myNode;
}
vector<int>levelOrder(struct Node * root){
    vector<int>levelArr;
    if(!root){
        return levelArr;
    }
    queue<struct Node *>q;
    q.push(root);
    while(!q.empty()){
        struct Node * temp=q.front();
        q.pop();
        levelArr.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return levelArr;
}
// ===================
// boundary traversal
// 
bool isLeaf(struct Node *cnode){
    return !cnode->left && !cnode->right;
}
void createLeftBoundary(struct Node * root,vector<int>&res){
    struct Node * curr=root->left;
    while(curr){
        if(!isLeaf(curr))res.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
    }
}
void createRightBoundary(struct Node * root,vector<int>&res){
    struct Node * cur2=root->right;
    vector<int>tempForward;
    while(cur2){
        if(!isLeaf(cur2))tempForward.push_back(cur2->data);
        if(cur2->right)cur2=cur2->right;
        else cur2=cur2->left;
    }
    for(int i=tempForward.size()-1;i>=0;i--){
        res.push_back(tempForward[i]);
    }
}
void createLeafBoundary(struct Node * root,vector<int>&res){
    if(isLeaf(root)){
        res.push_back(root->data);
    }
    if(root->left)createLeafBoundary(root->left,res);
    if(root->right)createLeafBoundary(root->right,res);
}
vector<int>boundaryTrav(struct Node * root){
    vector<int>res;
    if(!root)return res;
    if(!isLeaf(root))res.push_back(root->data);
    createLeftBoundary(root,res);
    createLeafBoundary(root,res);
    createRightBoundary(root,res);

    return res;
}
int main(){
    struct Node * root=newNode(1);
    root -> left = newNode(2);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(10);
    root -> left -> left -> left = newNode(5);
    root -> left -> left -> left -> left = newNode(6);
    root -> left -> left -> left -> right = newNode(12);
    root -> right = newNode(3);
    root -> right -> left = newNode(9);
    root -> right -> right = newNode(8);

    vector<int>levelView=levelOrder(root);
    for(auto it:levelView){
        cout<<it<<"--";
    }
    cout<<endl;
    vector<int>boundaryView=boundaryTrav(root);
    for(auto ib:boundaryView){
        cout<<ib<<"=";
    }

}