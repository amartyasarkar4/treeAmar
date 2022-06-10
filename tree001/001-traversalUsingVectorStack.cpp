#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node * left,* right;
};
struct Node * newNode(int data){
    struct Node * Node=(struct Node *)malloc(sizeof(struct Node));
    Node->data=data;
    Node->left=NULL;
    Node->right=NULL;

    return (Node);
}
vector<int> inOrderTrav(Node * curr){
    vector<int>inOrder;
    stack<Node*>s;
    while(true){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }else{
            if(s.empty())break;
            curr=s.top();
            inOrder.push_back(curr->data);
            s.pop();
            curr=curr->right;
        }
    }
    return inOrder;
}
vector<int>preOrderTrav(Node * curr){
    vector<int>preOrder;
    if(curr==NULL){
        return preOrder;
    }
    stack<Node *>s;
    s.push(curr);

    while(!s.empty()){
        Node * topNode=s.top();
        preOrder.push_back(topNode->data);
        s.pop();
        if(topNode->right!=NULL){
            s.push(topNode->right);
        }
        if(topNode->left!=NULL){
            s.push(topNode->left);
        }

    }
    return preOrder;
}
vector<int>postOrderTrav(Node * curr){
    vector<int>postOrder;
    if(curr==NULL){
        return postOrder;
    }
    stack<Node *>st;
    st.push(curr);
    while(!st.empty()||curr!=NULL){
        if(curr!=NULL){
            st.push(curr);
            curr=curr->left;
        }else{
            Node * temp=st.top()->right;
            if(temp==NULL){
                temp=st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while(!st.empty()&& temp==st.top()->right){
                    temp=st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }else curr=temp;
        }
        // Node * topNode=s.top();
        // // cout<<topNode->data<<endl;
        // if(topNode->right==NULL && topNode->left==NULL){
        //     postOrder.push_back(topNode->data);
        //     s.pop();
        // }
        // if(topNode->right!=NULL){
        //     s.push(topNode->right);
        // }
        // if(topNode->left!=NULL){
        //     s.push(topNode->left);
        // }
        // Node * finalTop=s.top();
        // postOrder.push_back(finalTop->data);
        // cout<<finalTop->data<<endl;
        // s.pop();
    }
    return postOrder;
}
int main(){
    // cout<<"Hello tree"<<endl;
    struct Node * root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root -> left -> left = newNode(4);
    root -> left -> right = newNode(5);
    root -> left -> right -> left = newNode(8);
    root -> right -> left = newNode(6);
    root -> right -> right = newNode(7);
    root -> right -> right -> left = newNode(9);
    root -> right -> right -> right = newNode(10);

    vector<int>inOrderV;
    inOrderV=inOrderTrav(root);
    cout<<"The inOrder Traversal is: ";
    for(int i=0;i<inOrderV.size();i++){
        cout<<inOrderV[i]<<"-";
    }
    cout<<"\n";

    vector <int> preOrderV=preOrderTrav(root);
    cout<<"The preOrder traversal is:  ";
    for(int i=0;i<preOrderV.size();i++){
        cout<<preOrderV[i]<<"-";
    }
    cout<<"\n";

    vector<int> postOrderV=postOrderTrav(root);
    cout<<"the PostOrder Traversal is : ";
    for(int i=0;i<postOrderV.size();i++){
        cout<<postOrderV[i]<<"-";
    }
    cout<<"\n";

}