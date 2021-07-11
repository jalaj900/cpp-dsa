//doubly linked list

#include <iostream>
using namespace std;

//node structure prev,data,next
//we can traverse in either direction ina doubly ll.

//creating node

class node
{

public:
    node *next;
    node *prev;
    int data;

    //constructor
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

//display function

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

//insert node at head

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

//insert node at tail

void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

//deletion of node at head

void deleteAtHead(node *&head)
{
    node *temp = head;
    head = head->next;
    head->prev = NULL;
}

//deletion of any node

void deletion(node *&head, int pos)
{

    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int count = 1;
    while (temp != NULL && count != pos){
        temp=temp->next;
        count++;
    }

    temp->prev->next=temp->next;
    
    if (temp->next!=NULL){
        temp->next->prev=temp->prev;
    }

    delete temp;
}


