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

 void KSumPaths(Node* root,int k,int &count,vector<int> temp){
if(!root) return ;
temp.push_back(root->data);
KSumPaths(root->left,k,count,temp);
KSumPaths(root->right,k,count,temp);
int size=temp.size();
int sum=0;
for(int i=size-1;i>=0;i--){
    sum+=temp[i];
    if(sum==k)
    count++;
}
temp.pop_back();
 }

int main(){
    Node* root=NULL;
    root=CreateTree(root);
    int k;
    cout<<"Enter Sum Value "<<endl;
    cin>>k;
    int ans=0;
    vector<int> temp;
    KSumPaths(root,k,ans,temp);
    cout<<ans;
    return 0;
}