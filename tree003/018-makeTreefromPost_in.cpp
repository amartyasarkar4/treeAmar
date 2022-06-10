#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node * right;
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
vector<int>levelOrder(struct Node * root){
    vector<int>levelArr;
    if(root==NULL)return levelArr;
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
// ==================================
// code for creating Tree from PostOrder & InOrder
// 
struct Node * createTreePostIn(vector<int>&postOrder,int postStart,int postEnd,vector<int>&inOrder,int inStart,int inEnd,map<int,int>&mp){
    if(postEnd<postStart||inStart>inEnd)return NULL;
    struct Node * root=new Node(postOrder[postEnd]);
    int elem=mp[root->data];
    int nElem=elem-inStart;
    root->right=createTreePostIn(postOrder,postStart+nElem,postEnd-1,inOrder,elem+1,inEnd,mp);
    root->left=createTreePostIn(postOrder,postStart,postStart+nElem-1,inOrder,inStart,elem-1,mp);

    return root;
}
struct Node * buildTree(vector<int>&postOrder,vector<int>&inOrder){
    int postStart=0,postEnd=postOrder.size()-1;
    int inStart=0,inEnd=inOrder.size()-1;
    map<int,int>mp;
    for(int i=0;i<=inEnd;i++){
        mp[inOrder[i]]=i;
    }
    // for(auto it:mp){
    //     cout<<it.first<<" : "<<it.second<<endl;
    // }
    return createTreePostIn(postOrder,postStart,postEnd,inOrder,inStart,inEnd,mp);
}
int main(){
    // vector<int>postOrder{6,12,5,4,10,2,9,8,3,1};
    // vector<int>inOrder={6,5,12,4,2,10,1,9,3,8};

    vector<int>postOrder{2,7,1,19,15,9,10,13,3,8,12};
    vector<int>inOrder={2,7,9,1,15,19,12,10,8,13,3};

    struct Node * root=buildTree(postOrder,inOrder);



    // struct Node * root=new Node(1);
    // root -> left = new Node(2);
    // root -> left -> left = new Node(4);
    // root -> left -> right = new Node(10);
    // root -> left -> left -> left = new Node(5);
    // root -> left -> left -> left -> left = new Node(6);
    // root -> left -> left -> left -> right = new Node(12);
    // root -> right = new Node(3);
    // root -> right -> left = new Node(9);
    // root -> right -> right = new Node(8);



    vector<int>levelView=levelOrder(root);
    for(auto it:levelView){
        cout<<it<<"--";
    }
}