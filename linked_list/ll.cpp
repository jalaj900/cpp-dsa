
#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    //constructor to initalize the node
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

//insert node at tail or end

void insertAtTail(node *&head, int val)
{

    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

//display the linked list

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

//insert at head

void insertAtHead(node *head, int val)
{

    node *n = new node(val);
    n->next = head;
    head = n;
}

//search an element

bool search(node *head, int key)
{

    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

//delete the head node

void deleteAtHead(node *head)
{
    node *todelete = head;
    head = head->next;

    delete todelete;
}

// delete any node

void deletenode(node *&head, int val)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;

    while (temp->next->data != val)
    {
        temp = temp->next;
    }

    node *todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}


//main function

int main()
{

    node *head = NULL;

    // function calls

    return 0;
}