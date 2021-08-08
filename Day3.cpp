//  Linked List
#include<iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void display(Node*);
Node* insert_beg(Node*,int);
Node* insert_end(Node*,int);
Node* delete_beg(Node*);
Node* delete_end(Node*);

Node * create(int n)
{
    Node* nptr=new Node();
    nptr->data=n;
    nptr->next=NULL;
    return nptr;
}

int main()
{
    Node* head = NULL;
    head=insert_beg(head,30);
    head=insert_beg(head,20);
    head=insert_beg(head,10);
    head=insert_end(head,40);
    head=insert_end(head,50);
    display(head);
    head=delete_beg(head);
    display(head);
    head=delete_end(head);
    display(head);
    return 0;
}

Node * insert_beg(Node * head,int m)
{
    Node* n=create(m);
    if(head==NULL)
    {
        head=n;
        return head;
    }
    n->next=head;
    head=n;
    return head;
}

Node * insert_end(Node * head,int m)
{
    Node* n=create(m);
    if(head==NULL)
    {
        head=n;
        return head;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    return head;
}

Node * delete_beg(Node * head)
{
    if(head==NULL)
    {
        cout<<"Nothing to delete"<<endl;
        return head;
    }
    Node* temp=head;
    head=temp->next;
    delete temp;
    return head;
}

Node * delete_end(Node * head)
{
    if(head==NULL)
    {
        cout<<"Nothing to delete"<<endl;
        return head;
    }
    Node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return head;
}

void display(Node * head)
{
    if(head==NULL)
    {
        cout<<"Linked List is Empty";
    }
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
