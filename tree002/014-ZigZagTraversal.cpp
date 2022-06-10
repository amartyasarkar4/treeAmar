#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * left;
    struct Node *  right;
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
vector<int>levelOrder(struct Node *root){
    queue<Node*>q;
    vector<int>ans;
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
vector<vector<int>> ZigZagOrder(struct Node * root){
    queue<struct Node *>qZ;
    vector<vector<int>>zigzagArr;
    bool leftToRight=false;
    qZ.push(root);
    while(!qZ.empty()){
        
        int size=qZ.size();
        cout<<size<<endl;
        vector<int>row(size);
        for(int i=0;i<size;i++){
            struct Node * temp=qZ.front();
            qZ.pop();
            cout<<"data: "<<temp->data<<endl;
            // cout<<i<<" "<<row[i]<<endl;
            // row.insert(0,temp->data);
            leftToRight?row[i]=temp->data:row[size-i-1]=temp->data;
            if(temp->left){
                qZ.push(temp->left);
            }
            if(temp->right){
                qZ.push(temp->right);
            }
        }
        leftToRight=!leftToRight;
        // for(int i=0;i<row.size();i++){
        //     // cout<<"hh: "<<row[i]<<endl;
        //     zigzagArr.push_back(row[i]);
        // }
        zigzagArr.push_back(row);
       
    }
    return zigzagArr;
}
int main(){
    struct Node * root=new Node(1);
    root -> left = new Node(2);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(10);
    root -> left -> left -> left = new Node(5);
    root -> left -> left -> left -> left = new Node(6);
    root -> left -> left -> left -> right = new Node(12);
    root -> right = new Node(3);
    root -> right -> left = new Node(9);
    root -> right -> right = new Node(8);

    vector<int>ansofLevelOrder=levelOrder(root);
    for(auto it:ansofLevelOrder){
        cout<<it<<"--";
    }

    vector<vector<int>>zigZag;
    zigZag=ZigZagOrder(root);
    for(auto it:zigZag){
        for(int i=0;i<it.size();i++){
            cout<<it[i]<<"--";
        }
        cout<<endl;
    }
}