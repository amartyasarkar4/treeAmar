#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node * left;
    struct Node * right;
};
struct Node * newNode(int val){
    struct Node * myNode=(struct Node *)malloc(sizeof(struct Node));
    myNode->left=NULL;
    myNode->right=NULL;
    return myNode;
}
int widthOfBinaryTree(struct Node * root){
    if(!root){
        return 0;
    }
    int ans=0;
    queue<pair<Node *,int>>q;
    q.push({
        root,
        0
    });
    while(!q.empty()){
        int size=q.size();
        int curMin=q.front().second;
        int leftMost,rightMost;
        cout<<"size: "<<size<<endl;
        for(int i=0;i<size;i++){
            int cur_id=q.front().second-curMin;
            Node * temp=q.front().first;
            q.pop();
            if(i==0)leftMost=cur_id;
            if(i==size-1)rightMost=cur_id;
            if(temp->left){
                q.push({
                    temp->left,
                    cur_id*2+1
                });
            };
            if(temp->right){
                q.push({
                    temp->right,
                    cur_id*2+2
                });
            }
        }
        cout<<"leftMost="<<leftMost<<" & rightMost="<<rightMost<<endl;
        ans=max(ans,rightMost-leftMost+1);
    }
    return ans;
}
int main(){
    struct Node * root=newNode(1);
    root -> left = newNode(3);
    root -> left -> left = newNode(5);
    root -> left -> left -> left = newNode(7);
    root -> right = newNode(2);
    root -> right -> right = newNode(4);
    root -> right -> right -> right = newNode(6);

    int maxWidth = widthOfBinaryTree(root);
    cout << "The maximum width of the Binary Tree is " << maxWidth;


}