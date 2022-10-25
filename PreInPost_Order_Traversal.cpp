#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* CreateBinaryTree(Node* root){
    int data;
    cout<<"Enter Data"<<endl;
    cin>>data;
    if(data==-1)return root;
    root=new Node(data);
    cout<<"Enter Data left to "<<data<<endl;
    root->left=CreateBinaryTree(root->left);
    cout<<"Enter Data right to "<<data<<endl;
    root->right=CreateBinaryTree(root->right);
    return root;
}

void InOrderTraversal(Node* &root){
    if(!root)return ;
    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}

void PreOrderTraversal(Node* &root){
    if(!root)return ;
    cout<<root->data<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);
}

void PostOrderTraversal(Node* &root){
    if(!root)return ;
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root=NULL;
    root=CreateBinaryTree(root);
    cout<<"PreOrder Traversal"<<endl;
    PreOrderTraversal(root);
    cout<<"InOrder Traversal"<<endl;
    InOrderTraversal(root);
    cout<<"PostOrder Traversal"<<endl;
    PostOrderTraversal(root);
    return 0;
}