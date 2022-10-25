#include<iostream>
#include<queue>
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

//Binary Tree Level Order Traversal 
void LevelOrderTraversal(Node* root){
    if(root==NULL) return ;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(q.empty()!=true){
            Node* temp=q.front();
            q.pop();
            if(temp==NULL){
                cout<<endl;
                if(q.empty()!=true){
                    q.push(NULL);
                }
            }
            else{
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);}
    }
}

int main(){
    Node* root=NULL;
    root=BinaryTreeCreation(root);
    cout<<"Level Order Traversal:"<<endl;
    LevelOrderTraversal(root);
    return 0;
}