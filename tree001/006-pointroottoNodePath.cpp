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
bool getPath(struct Node * root,vector<int>&rasta,int val){
    if(root==NULL){
        return false;
    }
    rasta.push_back(root->data);
    if(root->data==val){
        return true;
    }
    if(getPath(root->left,rasta,val)||getPath(root->right,rasta,val)){
        return true;
    }
    rasta.pop_back();
    return false;
}
int main(){
    struct Node * root=newNode(1);
    root->left=newNode(2);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->left->right->left=newNode(6);
    root->left->right->right=newNode(7);
    root->right=newNode(3);

    vector<int>path;
    bool present;

    present=getPath(root,path,7);
    if(present)cout<<"Yes Present."<<endl;
    else cout<<"Not present !!"<<endl;
    for(auto it:path){
        cout<<it<<' ';
    }


}