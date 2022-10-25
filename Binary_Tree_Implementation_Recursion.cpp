#include<iostream>
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

//Binary Tree Creation using Recursion
Node* BinaryTreeCreation(Node* root){
int input;
cout<<"Enter Data "<<endl;
cin>>input;
if(input==-1) return NULL;
if(root==NULL){
    root=new Node(input);
}
cout<<"Enter Data Left to "<<root->data<<endl;
root->left=BinaryTreeCreation(root->left);
cout<<"Enter Data Right to "<<root->data<<endl;
root->right=BinaryTreeCreation(root->right);
return root;
}

//Inorder Traversal 
void InorderTraversal(Node* root){
    if(root==NULL) return ;
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    InorderTraversal(root->right);
}

int main(){
    Node* root=NULL;
    root=BinaryTreeCreation(root);
    cout<<"Inorder Traversal: ";
    InorderTraversal(root);
    return 0;
}