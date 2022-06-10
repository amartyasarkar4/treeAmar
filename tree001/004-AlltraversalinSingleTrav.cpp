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
void allTreversal(Node * root,vector<int>&pre,vector<int>&in,vector<int>&post){
    stack<pair<Node*,int>>st;
    st.push({
        root,1
    });
    if(root==NULL)return;

    while(!st.empty()){
        auto it=st.top();
        st.pop();

        cout<<"it->second="<<it.second<<endl;
        if(it.second==1){
            cout<<"pushing in pre="<<it.first->data<<endl;
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL){
                st.push({
                    it.first->left,
                    1
                });
            }
        }

        else if(it.second==2){
            cout<<"pushing in in="<<it.first->data<<endl;
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL){
                st.push({
                    it.first->right,
                    1
                });
            }
        }

        else{
            cout<<"pushing in post="<<it.first->data<<endl;
            post.push_back(it.first->data);
        }
    }
}
int main(){
    struct Node * root = newNode(1);
    root -> left = newNode(2);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> right = newNode(3);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);

    vector<int>pre,in,post;
    allTreversal(root,pre,in,post);

    cout<<"The preOrder Traversal is: ";
    for(auto it:pre){
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<"The inOrder Traversal is: ";
    for(auto nodeVal:in){
        cout<<nodeVal<<" ";
    }
    cout<<"\n";
    cout<<"The postOrder Traversal is: ";
    for(auto nodeVal:post){
        cout<<nodeVal<<" ";
    }
    cout<<"\n";

}