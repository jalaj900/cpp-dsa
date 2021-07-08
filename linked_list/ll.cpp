//create node
//display ll
//insert at head
//insert at tail
//delete at head
//delete any node
//search element in ll
//reverse ll
//lenght of ll
//reverse k nodes(two methods)
//dectect a cycle
//remove a cycle
//intersection of two ll
//merge two sorted ll(two methods)
//put even pos nodes after odd pos nodes

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

//reverse a linked list
//there are two methods-:

//i.itterative method
node *reverse(node *&head)
{

    node *preptr = NULL;
    node *currptr = head;
    node *nextptr;

    while (nextptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = preptr;

        preptr = currptr;
        currptr = nextptr;
    }
    return preptr;
}

//ii. Recurcive method

node *reverse_node(node *&head)
{
    if (head == NULL || head->next == NULL)
    {

        return head;
    }

    node *newhead = reverse_node(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
//reverse k node in a linked list

node *reversek(node *&head, int k)
{
    node *currptr = head;
    node *prevptr = head;
    node *nextptr;

    int count = 0;

    while (currptr != NULL && count < k)
    {

        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        count++;
    }

    if (nextptr != NULL)
    {
        head->next = reversek(nextptr, k);
    }
    return prevptr;
}
//lenght of linked list
int lenght(node *&head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
//creating a cycle in a linked list

void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

//dectection of cycle in a linked list
bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast == slow)
    {
        return true;
    }

    return false;
}

//remove cycle from linked list

//find the intersection point and then move fast pointer to head
//then move both pointers by one step
//when the meet then make slow->next=NULL

void removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

//intersection of two linked list

int intersection(node *&head1, node *&head2)
{
    int l1 = lenght(head1);
    int l2 = lenght(head2);

    int d = 0;

    node *ptr1;
    node *ptr2;

    if (l1 > l2)
    {

        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }

    if (l1 < l2)
    {

        d = l2 - l1;
        ptr2 = head1;
        ptr1 = head2;
    }

    while (d)
    {
        ptr1 = ptr1->next;

        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }

    while (ptr1->next != NULL && ptr2->next != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

//merge two sorted ll

//two methods

//i.itterative method

node *merge(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;

    node *dummyNode = new node(-1);

    node *p3 = dummyNode;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }

        else
        {
            p3->next = p2;
            p2 = p2->next;
        }

        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummyNode;
}

//recursive method

node *merge_recur(node *&head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }

    node *result;

    if (head1->data < head2->data)
    {
        result = head1;
        result->next = merge_recur(head1->next, head2);
    }

    else
    {
        result = head2;
        result->next = merge_recur(head1, head2->next);
    }

    return result;
}

//put even pos nodes after odd pos nodes

void evenAfterOdd(node *head)
{
    node *odd = head;
    node *even = head->next;
    node *evenStart = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenStart;
    if (odd->next = NULL)
    {
        even->next = NULL;
    }
}
//main function

int main()
{

    node *head = NULL;

    // function calls

    return 0;
}