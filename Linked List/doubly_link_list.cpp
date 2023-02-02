#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int d)
    {
        data=d;
        next=NULL;
        prev=NULL;
    }
};
void insertAtHead(Node*&head,int d)
{
    Node*temp=new Node(d);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtTail(Node*head,int d)
{
    Node*insert=new Node(d);
    if(head==NULL)
    {
        head=insert;
        return;
    }
    Node*temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=insert;
    insert->prev=temp;
}
void deleteNode(Node*&head,int possition)
{
    if(possition==1)
    {
        Node*temp=head;
        temp->next->prev=NULL;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    Node * curr=head;
    Node*pre=NULL;
    int cnt=1;
    while(cnt<possition)
    {
        pre=curr;
        curr=curr->next;
        cnt++;
    }
    curr->prev=NULL;
    pre->next=curr->next;
    curr->next=NULL;
    delete curr;
}
void print(Node * &head)
{
    Node*temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node *head=NULL;
    insertAtHead(head,100);
    insertAtHead(head,50);
    insertAtHead(head,10);
    insertAtTail(head,200);
    insertAtTail(head,300);
    deleteNode(head,5);
    print(head);
    return 0;
}