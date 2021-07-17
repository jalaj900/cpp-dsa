//this method uses 2 stacks and the dequeue function is costly

#include <iostream>
#include <stack>

using namespace std;

class que
{
    stack<int> st1;
    stack<int> st2;

public:
    void push(int x)
    {
        st1.push(x);
    }

    int pop()
    {
        if (st1.empty() and st2.empty())
        {
            cout << "queue empty" << endl;
            return -1;
        }

        if (st2.empty())
        {
         while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            int topVal=st2.top();
            st2.pop();

            return topVal;
        }
    }

    bool empty(){
        if(st1.empty() and st2.empty()){
            return true;
        }
        return false;
    }
};