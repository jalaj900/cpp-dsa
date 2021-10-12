#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int t[100][100];

int solve(int e, int f)
{
    if (f == 0 || f == 1)
        return f;

    if (e == 1)
        return f;

    int mn = INT_MAX;

    for (int k = 1; k <= f; k++)
    {
        int temp = 1 + max(solve(e - 1, k - 1), solve(e, f - k));

        mn = min(mn, temp);
    }
    return mn;
}

int solve_dp(int e, int f)
{
    if (f == 0 || f == 1)
        return f;

    if (e == 1)
        return f;

    if (t[e][f] != -1)
        return t[e][f];

    int mn = INT_MAX;

    for (int k = 1; k <= f; k++)
    {
        int low,high;

        if (t[e - 1][k - 1] != -1)
        {
            low = t[e - 1][k - 1];
        }
        else
        {
            low=solve_dp(e-1,k-1);
            t[e-1][k-1]=low;
        }

        if(t[e][f-k]!=-1)
        {
            high=t[e][f-k];
        }
        else{
            high=solve_dp(e,f-k);
            t[e][f-k]=high;
        }
        int temp = 1 + max(high,low);

        mn = min(mn, temp);
    }
    return t[e][f]=mn;
}

int main()
{
    int f, e;
    cin >> e >> f;

    memset(t, -1, sizeof(t));

    //cout << solve(e, f) << endl;
    cout << solve_dp(e, f) << endl;
}