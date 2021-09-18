//connet the rope to get min cost
#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minh;

void min_cost()
{
    
     int cost = 0;
    while (minh.size() >= 2)
    {
       
        int first = minh.top();

        minh.pop();

        int second = minh.top();

        minh.pop();

        cost = cost + first + second;

        minh.push(first + second);
       
    }
     cout << cost;
}

int main()
{
    int size;

    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    min_cost();
}
