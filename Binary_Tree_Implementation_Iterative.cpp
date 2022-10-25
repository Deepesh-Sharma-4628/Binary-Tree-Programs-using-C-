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

//Binary Tree Creation Using Level Order Traversal
void BinaryTreeCreation(Node* &root){
    int input;
    cout<<"Enter Data for Root: "<<endl;
    cin>>input;
    if(input!=-1)
    root=new Node(input);
    else return ;
    queue<Node*>q;
    q.push(root);
    while(q.empty()!=true){
            Node* temp=q.front();
            q.pop();
            int leftdata,rightdata;
            cout<<"Enter Data left to "<<temp->data<<endl;
            cin>>leftdata;
            if(leftdata!=-1) {
                temp->left=new Node(leftdata);
                q.push(temp->left);}
            cout<<"Enter Data right to "<<temp->data<<endl;
            cin>>rightdata;
            if(rightdata!=-1) {
                temp->right=new Node(rightdata);
                q.push(temp->right);}
}
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
    BinaryTreeCreation(root);
    cout<<"Inorder Traversal: ";
    InorderTraversal(root);
    return 0;
}