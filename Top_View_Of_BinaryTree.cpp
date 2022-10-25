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

vector<int> TopViewTree(Node* root){
vector<int>ans;
if(!root) return ans;
map<int,int>mp;
queue<pair<Node*,int>>q;
q.push(make_pair(root,0));
while(!q.empty()){
    pair<Node*,int>  temp=q.front();
    q.pop();
    Node* frontnode=temp.first;
    int HD=temp.second;
    if(mp.find(HD)==mp.end())
    mp[HD]=frontnode->data;
    if(frontnode->left) q.push(make_pair(frontnode->left,HD-1));
    if(frontnode->right) q.push(make_pair(frontnode->right,HD+1));
}
for(auto i : mp){
    ans.push_back(i.second);
}
return ans;
}


int main(){
    Node* root=NULL;
    root=CreateTree(root);
    vector<int> ans=TopViewTree(root);
    for(auto i : ans){
        cout<<i<<" ";
    }
    return 0;
}


//////Time Complexity--: O(N logN)
//////Space Complexity--:O(N)