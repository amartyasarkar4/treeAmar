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
vector<vector<int>>findVertical(Node * root){
    map<int,map<int,multiset<int>>>nodes;
    queue<pair<Node*,pair<int,int>>>todo;

    todo.push({
        root,
        {
            0,
            0
        }
    });
    while(!todo.empty()){
        auto p=todo.front();
        todo.pop();
        Node * temp=p.first;

        int x=p.second.first,y=p.second.second;
        nodes[x][y].insert(temp->data);
        if(temp->left){
            todo.push({
                temp->left,
                {
                    x-1,
                    y+1
                }
            });
        }
        if(temp->right){
            todo.push({
                temp->right,
                {
                    x+1,
                    y+1
                }
            });
        }
    }
    vector<vector<int>>ans;
    for(auto p:nodes){
        vector<int>col;
        for(auto q:p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main(){
    struct Node * root = newNode(1);
    root -> left = newNode(2);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(10);
    root -> left -> left -> right = newNode(5);
    root -> left -> left -> right -> right = newNode(6);
    root -> right = newNode(3);
    root -> right -> left = newNode(9);
    root -> right -> right = newNode(10);

    vector<vector<int>>verticalTraversal;
    verticalTraversal=findVertical(root);
    cout<<"The Vertical Traversal is: "<<endl;
    for(auto vertical:verticalTraversal){
        for(auto nodeVal:vertical){
            cout<<nodeVal<<" ";
        }
        cout<<endl;
    }




}