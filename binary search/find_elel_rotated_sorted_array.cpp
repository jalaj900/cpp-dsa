#include <iostream>
using namespace std;

//code for binary search

int binary_search(int arr[],int start, int end , int ele)
{
    

    while (start <= end)
    {

        int mid = start + (end - start) / 2;    // this prevents int overflow

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
    return -1;

}

//to find the min element 

int find_min_ele(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;

        if (arr[mid] <= arr[prev])
            return mid;

        if (arr[mid + 1] < arr[mid])
            return mid + 1;

        if (arr[start] <= arr[mid])
            start = mid + 1;

        if (arr[mid] <= arr[end])
            end = mid - 1;
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
    cin >>ele;
    int index = find_min_ele(arr, n);

    // cout<<index<<endl;

    int p1 = binary_search(arr,0,index-1,ele);
    int p2 = binary_search(arr,index,n-1,ele);

    // cout<<p1<<endl;
    // cout<<p2<<endl;

    if(p1>0 && p2 <0)
    {
        cout<<p1<<endl;
    }
    else if(p1<0 && p2>0)
    {
        cout<< p2<<endl;
    }
    else
    {
        cout<<"element not found"<<endl;
    }

}