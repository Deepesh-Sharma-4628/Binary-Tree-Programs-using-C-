#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

struct Node* CreateTree(struct Node* root){
queue<struct Node*>q;
int data;
cout<<"Enter data for root"<<endl;
cin>>data;
root=new Node(data);
q.push(root);
while(!q.empty()){
    struct Node* temp=q.front();
    q.pop();
    int leftdata,rightdata;
    cout<<"Enter Data left to "<<temp->data<<endl;
    cin>>leftdata;
    if(leftdata!=-1){
        temp->left=new Node(leftdata);
        q.push(temp->left);
    }
    cout<<"Enter Data right to "<<temp->data<<endl;
    cin>>rightdata;
    if(rightdata!=-1){
        temp->right=new Node(rightdata);
        q.push(temp->right);
    }
}
return root;
}

Node* LCA(Node* root,int node1,int node2){
    if(!root) return NULL;
    if(root->data==node1 || root->data==node2){
        return root;
    }
    Node* left=LCA(root->left,node1,node2);
    Node* right=LCA(root->right,node1,node2);
    if(!left && !right)
        return NULL;
    else if(!left && right)
        return right;
    else if(left && !right)
        return left;
    else return root;
}
int main(){
    Node* root=NULL;
    root=CreateTree(root);
    int data1,data2;
    cout<<"Enter Data "<<endl;
    cin>>data1>>data2;
    Node* ans=LCA(root,data1,data2);
    cout<<ans->data;
}

////Time Complexity-->O(n)
///Space Complexity-->O(Height Of the Tree)