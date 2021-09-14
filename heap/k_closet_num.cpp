#include <iostream>
#include <queue>
#include <math.h>
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

    int x;

    cin >> x;

    priority_queue<pair<int, int>> maxh;

    for (int i = 0; i < size; i++)
    {

        maxh.push(make_pair(abs(arr[i] - x), arr[i]));

        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }

    while (maxh.size() > 0)
    {

        pair<int, int> top = maxh.top();

        cout << top.second << " ";
    }
}
