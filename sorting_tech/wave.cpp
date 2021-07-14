//tc=O(n)

#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void wave_sort(int arr[], int n)
{

    for (int i = 1; i < n - 1; i += 2)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(arr, i, i - 1);
        }

        if (arr[i]>arr[i+1] && i<=n-2){
            swap(arr,i,i+1);
        }
    }
}


int main(){
    int n;
    cin>>n;

    int arr[n];

    for (int i=0;i<n;i++){
        cin>>arr[i];
    }

    wave_sort(arr,n);

    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
}