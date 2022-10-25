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

//Leaf Nodes Count Of Binary Tree or Maximum Dept of Binary Tree
void LeafNodesCount(Node* root,int &count){
if(root==NULL) return ;
LeafNodesCount(root->left,count);
if(root->left==NULL && root->right==NULL)
    count++;
LeafNodesCount(root->right,count);
}

int main(){
    Node* root=NULL;
    root=BinaryTreeCreation(root);
    int count=0;
    cout<<"Leaf Nodes Count:";
    LeafNodesCount(root,count);
    cout<<count;
    return 0;
}