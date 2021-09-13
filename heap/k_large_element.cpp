// find the k largest elements
// eg - 3 2 1 5 ,  k = 3 => o/p = 2 3 5

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int size;

    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int k;

    cin >> k;

    priority_queue<int, vector<int>, greater<int>> minh;     //stl for min heap

    for (int i = 0; i < size; i++)
    {
        minh.push(arr[i]);

        if (minh.size() > k) // if size of heap is greater than k the pop the top
        {
            minh.pop();
        }
    }

    while (minh.size() > 0)
    {
        cout << minh.top() << " ";
        minh.pop();
    }

    return 0;
}
