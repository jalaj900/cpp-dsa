//this method uses 2 stacks and the dequeue function is costly

#include <iostream>
#include <stack>

using namespace std;

class que
{
    stack<int> st1;

public:
    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if (st1.empty())
        {
            cout << "queue empty" << endl;
            return -1;
        }
        int x = st1.top();
        st1.pop();

        if (st1.empty())
        {
            return x;
        }

        int topVal = pop();
        st1.push(x);

        return topVal;
    }
    bool empty()
    {
        if (st1.empty())
        {
            return true;
        }
        return false;
    }
};