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

//Height Of Binary Tree or Maximum Dept of Binary Tree
int HeightOfBinaryTree(Node* root){
int left,right;
if(root==NULL) return 0;
left=HeightOfBinaryTree(root->left);
right=HeightOfBinaryTree(root->right);
return max(left,right)+1;
}

int main(){
    Node* root=NULL;
    root=BinaryTreeCreation(root);
    cout<<"Height of Binary Tree:";
    cout<<HeightOfBinaryTree(root);
    return 0;
}