#include <iostream>
#include <algorithm>
using namespace std;

void lcs(string x, string y)
{
    int m = x.length();
    int n = y.length();
    int t[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {

                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    string s;
    int i = m;
    int j = n;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s.push_back(x[i - 1]);
            i--;
            j--;
        }

        else if (t[i - 1][j] > t[i][j - 1])
            i--;
        else
            j--;
    }

    reverse(s.begin(), s.end());

    cout << s << endl;
}

int main()
{
    string x, y;

    cin >> x >> y;

    lcs(x, y);

    return 0;
}