#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};
class Solution{
    public:
        void recursionforRight(Node * root,int level,vector<int>&res){
            if(root==NULL)return;
            if(res.size()==level)res.push_back(root->data);
            recursionforRight(root->right,level+1,res);
            recursionforRight(root->left,level+1,res);
        }
        void recursionforLeft(Node * root2,int level,vector<int>&res2){
            if(root2==NULL)return;
            if(res2.size()==level)res2.push_back(root2->data);
            recursionforLeft(root2->left,level+1,res2);
            recursionforLeft(root2->right,level+1,res2);

        }
        vector<int>rigthSideView(Node * root){
            vector<int>res;
            recursionforRight(root,0,res);
            return res;
        }
        vector<int>leftSideview(Node * root2){
            vector<int>res2;
            recursionforLeft(root2,0,res2);
            return res2;
            for(int i=0;i<res2.size();i++){
                cout<<res2[i]<<" ";
                cout<<"hello";
            }
        }
};
// ==================================

// ===========================================
// void recursionforRight(Node * root,int level,vector<int>&res){
//     if(root==NULL)return;
//     if(res.size()==level)res.push_back(root->data);
//     recursionforRight(root->right,level+1,res);
//     recursionforRight(root->left,level+1,res);
// }
// void recursionforLeft(Node * root2,int level,vector<int>&res2){
//     if(root2==NULL)return;
//     // cout<<root2->data<<endl;
//     if(res2.size()==level)res2.push_back(root2->data);
//     recursionforLeft(root2->left,level+1,res2);
//     recursionforLeft(root2->right,level+1,res2);
// }
// vector<int>rigthSideView(Node * root){
//     vector<int>res;
//     recursionforRight(root,0,res);
//     return res;
// }
// vector<int>leftSideview(Node * root2){
//     vector<int>res2;
//     recursionforLeft(root2,0,res2);
//     return res2;
//     for(int i=0;i<res2.size();i++){
//         cout<<res2[i]<<" ";
//         cout<<"hello";
//     }
// }
// ====================================
// 
// ================================================

vector<int>bottomView(Node * root){
    vector<int>ans;
    if(root==NULL)return ans;
    map<int,int>mpp;
    queue<pair<Node*,int>>q;

    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node * node=it.first;
        int line=it.second;
        mpp[line]=node->data;

        if(node->left!=NULL){
            q.push({node->left,line-1});
        }
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}
vector<int>topView(Node * root){
    vector<int>ans;
    if(root==NULL)return ans;
    map<int,int>mpp;
    queue<pair<Node*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        Node * node=it.first;
        int line=it.second;
        if(mpp.find(line)==mpp.end())mpp[line]=node->data;

        if(node->left!=NULL){
            q.push({node->left,line-1});
        }
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
    }
    for(auto it:mpp){
        ans.push_back(it.second);
    }
    return ans;
}
//================================================= 
// 
// ========================================
struct Node * newNode(int val){
    struct Node * myNode=(struct Node *)malloc(sizeof(struct Node));
    myNode->data=val;
    myNode->left=NULL;
    myNode->right=NULL;

    return myNode;
}
vector<int>morisInOrderTraversal(Node * root){
    vector<int>inOrder;
    Node * curr=root;

    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<"Curr->data: "<<curr->data<<endl;
            inOrder.push_back(curr->data);
            curr=curr->right;
        }else{
            Node * prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){
                cout<<prev->data<<endl;
                prev->right=curr;
                curr=curr->left;
            }else{
                prev->right=NULL;
                cout<<"from ano: "<<curr->data<<endl;
                inOrder.push_back(curr->data);
                curr=curr->right;
            }
        }
    }
    return inOrder;
}
vector<int>morisPreOrderTraversal(Node * root){
    vector<int>preOrder;
    Node * cur=root;
    while(cur!=NULL){
        if(cur->left==NULL){
            preOrder.push_back(cur->data);
            cur=cur->right;
        }else{
            Node * prev=cur->left;
            while(prev->right!=NULL && prev->right!=cur){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=cur;
                preOrder.push_back(cur->data);
                cur=cur->left;
            }else{
                prev->right=NULL;
                cur=cur->right;
            }
        }
    }
    return preOrder;
}
int main(){
    struct Node * root=newNode(1);
    root -> left = newNode(2);
    root -> right = newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> left -> right -> right = newNode(6);

    vector<int>inOrder;
    inOrder=morisInOrderTraversal(root);
    cout<<"The Moris InOrder Traversal is: ";
    for(int i=0;i<inOrder.size();i++){
        cout<<inOrder[i]<<' ';
    }
    cout<<"\n";
    vector <int>preOrder;
    preOrder=morisPreOrderTraversal(root);
    cout<<"The Moris PreOrder Traversal is: ";
    for(int i=0;i<preOrder.size();i++){
        cout<<preOrder[i]<<" ";
    }
    cout<<"\n";

    Solution s1;
    vector<int>rightView;
    rightView=s1.rigthSideView(root);

    cout<<"Right Side View Is: ";
    for(int i=0;i<rightView.size();i++){
        cout<<rightView[i]<<" ";
    }
    cout<<"\n";

    vector<int>leftView;
    leftView=s1.leftSideview(root);

    cout<<"Left Side View is: ";
    for( int i=0;i<leftView.size();i++){
        cout<<leftView[i]<<" ";
    }
    cout<<"\n";

    vector<int>underView;
    underView=bottomView(root);
    for(int i=0;i<underView.size();i++){
        cout<<underView[i]<<" ";
    }
    cout<<"\n";

    vector<int>highView;
    highView=topView(root);
    for(int i=0;i<highView.size();i++){
        cout<<highView[i]<<' ';
    }
    cout<<"\n";

    return 0;
}