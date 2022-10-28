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

 Node* CreateTree(Node* root){
queue<Node*>q;
int data;
cout<<"Enter data for root"<<endl;
cin>>data;
root=new Node(data);
q.push(root);
while(!q.empty()){
    Node* temp=q.front();
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

Node* KthAncestor(Node* root,int k,int node){
    if(!root) return NULL;
    if(root->data==node) return root;
    Node* left=KthAncestor(root->left,k,node);
    Node* right=KthAncestor(root->right,k,node);
    if(left && !right){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return left;
    }

    else if(!left && right){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}
int  KthAncestor_Of_BinaryTree(Node* root,int k,int node){
Node* ans=KthAncestor(root,k,node);
if(!ans || ans->data==node)
    return -1;
return ans->data;
}

int main(){
    Node* root=NULL;
    root=CreateTree(root);
    int k,node;
    cout<<"Enter Node Data "<<endl;
    cin>>node;
    cout<<"Enter Ancestor Number "<<endl;
    cin>>k;
    int ans=KthAncestor_Of_BinaryTree(root,k,node);
    cout<<ans;
   return 0;
}
//1 2 6 3 -1 -1 7 -1 4 8 -1 5 -1 -1 -1 -1 -1