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

pair<int,int> MaxSum(Node* root){
    pair<int,int> ans;
    if(!root){
        ans= make_pair(0,0);
        return ans;
    }

    pair<int,int> left=MaxSum(root->left);
    pair<int,int> right=MaxSum(root->right);

    ans.first=left.second+right.second+root->data;
    ans.second=max(left.first,left.second)+max(right.first,right.second);
    return ans;
}
int Max_Sum_Of_Non_Adjacent_Node(Node* root){
    if(!root)return 0;
    pair<int,int> res=MaxSum(root);
    return max(res.first,res.second);
}

int main(){
    Node* root=NULL;
    root=CreateTree(root);
    cout<<Max_Sum_Of_Non_Adjacent_Node(root);
    return 0;
}