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
vector<int>levelOrder(Node *root){
    vector<int>levelArr;
    if(!root)return levelArr;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        struct Node * temp=q.front();
        q.pop();
        levelArr.push_back(temp->data);
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right)q.push(temp->right);
    }
    return levelArr;
}
// =======================================================
// maxPathSum
// 
int findMaxPathSum(struct Node * root,int & maxi){
    if(root==NULL)return 0;
    int leftPathSum=max(0,findMaxPathSum(root->left,maxi));
    int rightPathSum=max(0,findMaxPathSum(root->right,maxi));
    int val=root->data;
    maxi=max(maxi,(leftPathSum+rightPathSum)+val);
    cout<<"val: "<<val<<"maxi: "<<maxi<<endl;
    int rval=max(leftPathSum,rightPathSum)+val;
    cout<<"rval:"<<rval;
    return rval;
}
int maxPathSum(struct Node * root){
    int maxi=INT16_MIN;
    // cout<<"("<<maxi;
    findMaxPathSum(root,maxi);
    return maxi;
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

    // struct Node * root = newNode(-10);
    // root -> left = newNode(9);
    // root -> right = newNode(20);
    // root -> right -> left = newNode(15);
    // root -> right -> right = newNode(7);

    vector<int>levelView=levelOrder(root);
    for(auto it:levelView){
        cout<<it<<"--";
    }

    int maxpathSum=maxPathSum(root);
    cout<<"maximum path sum is: "<<maxpathSum;
}