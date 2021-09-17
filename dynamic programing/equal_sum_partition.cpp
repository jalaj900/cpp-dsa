
#include <bits/stdc++.h>

using namespace std;

// Returns true if arr[] can be partitioned
// in two subsets of equal sum, otherwise false
bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;

    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    bool t[n + 1][sum / 2 + 1];

    // initialize top row as true

    for (int i = 0; i < n + 1; i++)
    {
        for (j = 0; j < sum / 2 + 1; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            if (j == 0)
            {
                t[i][j] = true;
            }
        }
    }

    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < sum / 2 + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[sum/2][n];
}

// Driver Code
int main()
{
    

    int n ;
    cin>>n;

    int arr[n] ;
    //= {3, 1, 1, 2, 2, 1};
    
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    // Function call
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets of equal "
                "sum";
    else
        cout << "Can not be divided into"
             << " two subsets of equal sum";
    return 0;
}