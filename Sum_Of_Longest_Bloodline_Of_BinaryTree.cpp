//Sium of nodes on the longest path from root of leaf node
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

void SumOfLongestPath(Node* root,pair<int,int> &ans,int curr_sum,int curr_length){
if(!root){
if(curr_length>ans.second){
    ans.second=curr_length;
    ans.first=curr_sum;
}

else if(curr_length==ans.second)
    ans.first=max(ans.first,curr_sum);
return ;
}

curr_sum+=root->data;
SumOfLongestPath(root->left,ans,curr_sum,curr_length+1);
SumOfLongestPath(root->right,ans,curr_sum,curr_length+1);
return ;
}

int SumOfNodes(Node* root){
    if(!root)return 0;
    pair<int,int> ans=make_pair(0,0);              ////ans.first-->Max SUM    ans.second-->Max length 
    int curr_length=0;
    int curr_sum=0;
    SumOfLongestPath(root,ans,curr_sum,curr_length);
    return ans.first;
}
int main(){
    Node* root=NULL;
    root=CreateTree(root);
    cout<<SumOfNodes(root);
}


/////Time Complexity --> O(n)
////Space Complexity --->O(n)