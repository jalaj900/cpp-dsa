
#include <bits/stdc++.h>

using namespace std;
int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int dp[n + 1][sum + 1];
    // Initializing the first value of matrix
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // if the value is greater than the sum
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int count(int arr[], int n, int diff)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int reqSum = (diff + sum) / 2;
    return subsetSum(arr, n, reqSum);
}

int main()
{

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int diff;
    cin >> diff;

    cout << count(arr, n, diff);
}