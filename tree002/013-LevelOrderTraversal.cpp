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
vector<int>levelOrder(struct Node * root){
    // if(!root){
    //     return ;
    // }
    queue<Node*>q;
    vector<int>levelArr;
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
const int n=1e7+10;
int arrHeap[n]={};
void heapArrMaking(struct Node * root){
    // if(!root){
    //     return ;
    // }
    queue<pair<Node*,int>>q;
    // vector<int>levelArr;
    q.push({root,0});
    while(!q.empty()){
        struct Node * temp=q.front().first;
        int parent=q.front().second;
        q.pop();
        // levelArr.push_back(temp->data);
        arrHeap[parent]=temp->data;
        cout<<"hello "<<temp->data<<endl;
        if(temp->left){
            q.push({temp->left,parent*2+1});
        }
        if(temp->right){
            q.push({temp->right,parent*2+2});
        }
    }
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
    vector<int>ansOfLevelOrder;
    ansOfLevelOrder=levelOrder(root);
    for(auto it:ansOfLevelOrder){
        cout<<""<<it<<"-";
    }
    heapArrMaking(root);
    for(int i=0;i<17;i++){
        cout<<i<<":"<<arrHeap[i]<<endl;
    }
}