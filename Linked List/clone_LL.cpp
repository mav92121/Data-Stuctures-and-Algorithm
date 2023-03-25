// https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    struct Node*arb;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int d) 
{
    Node* newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail -> next = newNode;
        tail = newNode;
    }
}
Node *copyList(Node *head)
{
    //step 1: Create a Clone List
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;
    
    Node* temp = head;
    while(temp != NULL) 
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp -> next;
    }
    
    // step 2: insert nodes of Clone List in between originalList
    
    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    
    while(originalNode != NULL && cloneNode != NULL) {
        Node* next = originalNode -> next;
        originalNode -> next = cloneNode;
        originalNode = next;
        
        next = cloneNode -> next;
        cloneNode -> next = originalNode;
        cloneNode  = next;
    }
    
    // step 3: Random pointer copy
    
    temp=head;
    
    while(temp) 
    { 
        if(temp->next!=NULL)
        {
            temp->next->arb=temp->arb ? temp->arb->next:temp->arb;
            
        }
        temp=temp->next->next;
    }
    
    //step 4: revert step 2 changes
    Node* original = head;
    Node* copy = cloneHead;
    
        while (original && copy)
        {
            original->next=copy->next;
            original=original->next;
            if(original)
            {
                copy->next=original->next;
            }
            copy = copy->next;
        }

    // step 5 answer return
    return cloneHead;
}