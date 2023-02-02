#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void insertAtHead(Node * &head, int d)
{
    Node*temp=new Node(d);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    temp->next=head;
    head=temp;
}
void insertAtTail(Node*&head, int d)
{
    Node*temp=head;
    Node*insert=new Node(d);
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next=insert;
}
void insertAtPosition(Node*&head,int position,int d)
{
    Node * insert=new Node(d);
    Node * temp=head;
    int cnt=1;
    if(position==1)
    {
        insert->next=head;
        head=insert;
        return;
    }
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    insert->next=temp->next;
    temp->next=insert;
}
void deleteNode(Node*&head,int position)
{
    Node*temp=head;
    if(position==1)
    {
        head=head->next;
        delete temp;
        return;
    }
    int cnt=1;
    while(cnt<position-1)
    {
        temp=temp->next;
        cnt++;
    }
    temp->next=temp->next->next;
}
void print(Node*&head)
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
    Node * head=NULL;
    insertAtHead(head,100);
    insertAtHead(head,60);
    insertAtHead(head,50);
    insertAtHead(head,10);
    insertAtTail(head,89);
    insertAtPosition(head,6,99);
    deleteNode(head,6);
    print(head);
    return 0;
}