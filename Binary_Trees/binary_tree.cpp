#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};
Node* buildTree(Node*root,Node*&ans)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);    
    if(ans==NULL)
    {
        ans=root;
    }
    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left,ans);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right,ans);
    return root;

}

void level(Node*node,queue<Node*>&q,vector<int>&ans) // recurcive approach
{
    if(node==NULL)return;
    int size=q.size();
    while(size--)
    {
        Node*front=q.front();
        q.pop();
        ans.push_back(front->data);
        if(front->left)q.push(front->left);
        if(front->right)q.push(front->right);
    }
    if(q.empty())return;
    node=q.front();
    return level(node,q,ans);
}

void levelOrder(Node*root) // using iterative
{
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size(); // processing same level nodes
        while(size--)
        {
            Node*front=q.front();
            q.pop();
            cout<<front->data<<" ";
            if(front->left)q.push(front->left);
            if(front->right)q.push(front->right);
        }
        cout<<endl;
    }


    
   

}
void inorder(Node*root) // L N R
{
    if(root==NULL)return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Node*root) // N L R
{
    if(root==NULL)return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node*root) // L R N
{
    if(root==NULL)return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
   Node*root=NULL;
   // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

   Node*ans=NULL; // this is the root of the tree
   buildTree(root,ans);
   levelOrder(ans);
    // inorder(ans);
   return 0;
}
