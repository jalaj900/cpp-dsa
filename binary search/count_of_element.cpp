#include <iostream>
using namespace std;

int binary_search_1st_occur(int arr[], int ele, int n)
{
    int start = 0;
    int end = n - 1;
    int result =-1;
    while (start <= end)
    {

        int mid = start + (end - start) / 2;    // this prevents int overflow

        if (ele == arr[mid])
        {
            result=mid;
            end=mid-1;
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
    return result;

}

int binary_search_last_occur(int arr[], int ele, int n)
{
    int start = 0;
    int end = n - 1;
    int result =-1;
    while (start <= end)
    {

        int mid = start + (end - start) / 2;    

        if (ele == arr[mid])
        {
            result=mid;
            start=mid+1;
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
    return result;

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
    int ele;
    cin>>ele;
    int first=binary_search_1st_occur(arr,ele,n);
    int last=binary_search_last_occur(arr,ele,n);

    cout<<last-first +1<<endl;
}