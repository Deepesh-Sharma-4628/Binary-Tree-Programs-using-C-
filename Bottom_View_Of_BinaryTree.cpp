#include<iostream>
#include<queue>
#include<map>
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

vector<int> BottomView(Node* root){
    vector<int> ans;
    if(!root)return ans;
    queue<pair<Node*, int>>q;
    map<int,int>mp;
    q.push(make_pair(root,0));
    while(!q.empty()){
        pair<Node* , int> temp=q.front();
        q.pop();
        Node* FrontNode=temp.first;
        int HorizontalDistance=temp.second;
        mp[HorizontalDistance]=FrontNode->data;
        if(FrontNode->left)
        q.push(make_pair(FrontNode->left,HorizontalDistance-1));
        if(FrontNode->right)
        q.push(make_pair(FrontNode->right,HorizontalDistance+1));
    }

    for(auto i : mp){
        ans.push_back(i.second);
    }
    return ans;
}


int main(){
Node* root=NULL;
BinaryTreeCreation(root);
vector<int> res=BottomView(root);
for(auto i:res){
    cout<<i<<" ";
}
}