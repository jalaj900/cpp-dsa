#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

typedef pair<int,int> ppi;

int main()
{
    int size;

    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    priority_queue <ppi> maxh;  //stl for max heap

    unordered_map<int, int> mp;

    for (int i = 0; i < size; i++)
    {
        mp[arr[i]]++;     //making hash table
    }

    for (auto i = mp.begin(); i != mp.end(); i++)
    {

        maxh.push(make_pair(i->second, i->first));       //pushing map into maxh
    
    }


    while (maxh.size() >0)
    {
        pair<int, int> top = maxh.top();

        int freq = top.first;
        int ele = top.second;
        
        for(int i=1;i<=freq;i++)       //printing ele
        {
            cout<<ele<<" ";
        }
        maxh.pop();
    }
}