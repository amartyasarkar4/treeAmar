#include<bits/stdc++.h>
using namespace  std;

struct Node{
    int data;
    struct Node * left,*right;
    Node(int val){
        this->data=val;
        this->left,this->right=NULL;
    }
};
vector<int>levelOrder(struct Node * root){
    vector<int>ans;
    if(root==NULL)return ans;
    queue<struct Node *>q;
    q.push(root);
    while(!q.empty()){
        struct Node * temp=q.front();
        q.pop();
        ans.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    return ans;
}
struct Node * makeTreeFromIn_PreOrder(int InOrder[],int PreOrder[],int preStart,int preEnd,int Instart,int InEnd,map<int,int>&mp){
    // for(auto it:mp){
    //     cout<<it.first<<": "<<it.second<<endl;
    // }
    
    cout<<"s:"<<preStart<<" e:"<<preEnd<<endl;
    cout<<"hello"<<PreOrder[preStart]<<endl;
    if(preStart>preEnd||Instart>InEnd){
        return NULL;
    }
    struct Node * root=new Node(PreOrder[preStart]);
    int elem=mp[root->data];
    int nelem=elem-Instart;
    cout<<"sI:"<<Instart<<" eI:"<<InEnd<<endl;
    cout<<"elem:"<<elem<<" nElem:"<<nelem<<endl;
    root->left=makeTreeFromIn_PreOrder(InOrder,PreOrder,preStart+1,preStart+nelem,Instart,elem-1,mp);
    root->right=makeTreeFromIn_PreOrder(InOrder,PreOrder,preStart+nelem+1,preEnd,elem+1,InEnd,mp);

    cout<<root->data<<endl;
    return root;
}
int main(){

    int inOrder[10]={6,5,12,4,2,10,1,9,3,8};
    int preOrder[10]={1,2,4,5,6,12,10,3,9,8};
    int instart=0,preStart=0;
    int inEnd=9,preEnd=9;
    map<int,int>mp;
    for(int i=0;i<10;i++){
        mp[inOrder[i]]=i;
    }
    cout<<"what: "<<preOrder[preStart]<<endl;
    struct Node * treeRoot=makeTreeFromIn_PreOrder(inOrder,preOrder,preStart,preEnd,instart,inEnd,mp);
    
    vector<int>levelViewofCreatedTree=levelOrder(treeRoot);
    for(auto it:levelViewofCreatedTree){
        cout<<it<<"--";
    }
    
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

    // vector<int>levelView=levelOrder(root);
    // for(auto it:levelView){
    //     cout<<it<<"--";
    // }

}