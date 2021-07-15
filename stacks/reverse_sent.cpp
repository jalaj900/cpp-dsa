#include <iostream>
#include <stack>

using namespace std;

void reverse(string s)
{
    stack<string> st;  //stack stl

    for (int i = 0; s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }

        st.push(word);
    }
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    cout << endl;
}
