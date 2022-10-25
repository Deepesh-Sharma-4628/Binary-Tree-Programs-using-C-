#include<iostream>
#include<queue>
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

void CreateBinaryTree(Node* &root){
int data;
cout<<"Enter Data For root "<<endl;
cin>>data;
root=new Node(data);
queue<Node*>q;
q.push(root);
while(!q.empty()){
    Node* temp=q.front();
    q.pop();
    cout<<"Enter Data Left To "<<temp->data<<endl;
    int leftdata;
    cin>>leftdata;
    if(leftdata!=-1){
        temp->left=new Node(leftdata);
        q.push(temp->left);
    }
    cout<<"Enter Data right To "<<temp->data<<endl;
    int rightdata;
    cin>>rightdata;
    if(rightdata!=-1){
        temp->right=new Node(rightdata);
        q.push(temp->right);
    }
}
}

pair<int,int> DiameterOfBinaryTree(Node* root,pair<int,int>ans){
     if(!root){
            ans=make_pair(0,0);
            return ans;}
        pair<int,int> left=DiameterOfBinaryTree(root->left,ans);
        pair<int,int> right=DiameterOfBinaryTree(root->right,ans);
        int LeftSubTreeDiameter=left.first;
        int RightSubTreeDiameter=right.first;
        int BothTreeDiameter=left.second+right.second;
        ans.second=max(left.second,right.second)+1;
        ans.first=max(max(LeftSubTreeDiameter,RightSubTreeDiameter),BothTreeDiameter);
        return ans;
    }

int main(){
    Node* root=NULL;
    CreateBinaryTree(root);
    cout<<endl;
    pair<int,int>res;
    res=DiameterOfBinaryTree(root,res);
    cout<<res.first<<endl;
    return 0;
}