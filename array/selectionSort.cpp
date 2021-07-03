//sorting an array in ascending
//selection sort
//find the min element in umsorted array
//and swap it with element at begining

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter size of array";
    cin>>n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
 
    }
return 0;
}

