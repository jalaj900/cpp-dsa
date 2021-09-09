#include <iostream>
using namespace std;

int binary_search(int arr[], int ele, int n)
{
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {

        int mid = start + (end - start) / 2; // this prevents int overflow

        if (ele == arr[mid])
        {
            return mid;
        }

        else if (ele < mid)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int main()
{

    int n;
    cin >> n;
    int arr[n];

    //input array in descending order

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ele;
    cin >> ele;
    cout << binary_search(arr, ele, n);
}