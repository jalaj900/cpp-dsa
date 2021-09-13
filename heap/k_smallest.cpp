//we have to find kth smallest so we use max heap

#include <iostream>
#include <queue>
using namespace std;


int main()
{
    int size;

    cin>>size;

    int arr[size];

    for (int i=0 ;i<size;i++)
    {
        cin>>arr[i];
    }

    int k;

    cin>> k;

    priority_queue<int> maxh;   // stl for max heap

    for (int i=0;i<size;i++)
    {
        maxh.push(arr[i]);

        if(maxh.size()>k)         // if size of heap is greater than k the pop the top 
        {                        
            maxh.pop();
        }

    }

  cout<< maxh.top();

  return 0;

}
