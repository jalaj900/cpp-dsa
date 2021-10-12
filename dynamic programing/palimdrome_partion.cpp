#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

bool isPalimdrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int t[1001][1001];

int solve(string s, int i, int j)
{
    if (i >= j)
        return 0;

    if (isPalimdrome(s, i, j))
        return 0;

    if (t[i][j] != -1)
        return t[i][j];
    int left, right, mn = INT_MAX, ans;

    for (int k = i; k <= j - 1; k++)
    {

        if (t[i][k] != -1)
        {
            left = t[i][k];
        }
        else
        {
            left = solve(s, i, k);
            t[i][k] = left;
        }

        if (t[k + 1][j] != -1)
        {
            right = t[k + 1][j];
        }
        else
        {
            right = solve(s, k + 1, j);
            t[k + 1][j] = right;
        }
        int temp = right + left +1;
        ans = min(ans,temp);
    }

    return ans;
}

int main()
{
    string s;
    cin >> s;

    memset(t, -1, sizeof(t));

    cout << solve(s, 0, s.length()-1);
}