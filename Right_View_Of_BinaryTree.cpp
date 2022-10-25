#include<iostream>
#include<vector>
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

void LeftViewTree(Node* root,vector<int> &ans,int level){
if(!root)return ;
if(level==ans.size())
ans.push_back(root->data);
LeftViewTree(root->right,ans,level+1);
LeftViewTree(root->left,ans,level+1);
return ;
}


int main(){
    Node* root=NULL;
    root=CreateTree(root);
    vector<int> ans;
    LeftViewTree(root,ans,0);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}