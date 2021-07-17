//queue using stack
//fifo is used in stack

#include <iostream>
using namespace std;

#define n 100

class queue
{
    int *arr;
    int back, front;

    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    int push(int x)
    {
        if (back == -1)
        {
            cout << "queue overflow";
            return;
        }

        back++;
        arr[back] = x;
        if (front == -1)
        {
            front++;
        }
    }

    void deque()
    {
        if (front == -1 || front > back)
        {
            cout << "empty queue" << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "no element" << endl;
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};
