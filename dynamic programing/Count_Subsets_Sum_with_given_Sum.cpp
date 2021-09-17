
#include <bits/stdc++.h>

using namespace std;

int subsetSum(int a[], int n, int sum)
{
    // Initializing the matrix
    int tab[n + 1][sum + 1];
  // Initializing the first value of matrix
    tab[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        tab[0][i] = 0;
    for (int i = 1; i <= n; i++)
        tab[i][0] = 1;
  
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
          // if the value is greater than the sum 
            if (a[i - 1] > j)
                tab[i][j] = tab[i - 1][j];
            else
            {
                tab[i][j] = tab[i - 1][j] + tab[i - 1][j - a[i - 1]];
            }
        }
    }
  
  
    return tab[n][sum];
}
  


// Driver Code
int main()
{
    

    // int n ;
    // cin>>n;

    // int arr[n] ;
    // //= {3, 1, 1, 2, 2, 1};
    
    // for(int i=0;i<n;i++)
    // {
    //     cin>>arr[i];
    // }
    
    // int sum;
    // cin>> sum;

    int n = 4;
    int arr[] = {3,3,3,3};
    int sum = 6;
    // Function call
    cout<< subsetSum(arr, n,sum);
       
    
}