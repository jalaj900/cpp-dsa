
#include <bits/stdc++.h>

using namespace std;
bool subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    bool t[n + 1][sum + 1];
    // Initializing the first value of matrix
    t[0][0] = true;
    for (int i = 1; i <= sum; i++)
        t[0][i] = false;
    for (int i = 1; i <= n; i++)
        t[i][0] = true;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // if the value is greater than the sum
            if (a[i - 1] <= j)
                t[i][j] = t[i - 1][j] || t[i - 1][j - a[i - 1]];
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }

    int sum;
    cin>>sum;

    if (subsetSum(arr,n,sum)==true)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No"<<endl;
    }
    
    return 0;
}