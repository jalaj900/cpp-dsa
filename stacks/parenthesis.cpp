//balanced parenthesis using stack

#include <bits/stdc++.h>
using namespace std;
bool isvalid(string s)
{

    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        bool ans = true;
        if (s[i] == '(' or s[i] == '{' or s[i] == '[')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')' && !st.empty())
        {
            if (st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }

        else if (s[i] == ']' && !st.empty())
        {
            if (st.top() == ']')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }

        else if (s[i] == '}' && !st.empty())
        {
            if (st.top() == '}')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
}

int main()
{
    string s = "{[()]}";
    if (isvalid(s))
    {
        cout << "valid" << endl;
    }
    else
    {
        cout << "not valid" << endl;
    }
}