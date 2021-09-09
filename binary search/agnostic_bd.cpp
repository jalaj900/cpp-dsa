// we dont how whether the array is sorted in asc or desc order

#include <iostream>
using namespace std;

int binary_search(int arr[], int ele, int n)
{
    int start = 0;
    int end = n - 1;
    if (n == 1)
    {
        return 0;
    }
    else
    {
        if (arr[0] < arr[1])
        {
            while (start <= end)
            {

                int mid = start + (end - start) / 2; // this prevents int overflow

                if (ele == arr[mid])
                {
                    return mid;
                }

                else if (ele < mid)
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }

        else
        {
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
        }
    }

    return -1;
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
    int ele;
    cin >> ele;
    cout << binary_search(arr, ele, n);
}