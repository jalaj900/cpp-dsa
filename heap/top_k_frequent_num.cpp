//top k frequent numbers
// use unorederd_map to create hash map

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

    int k;

    cin >> k;

    priority_queue<ppi, vector<ppi>, greater<ppi>> minh; //stl for min heap

    unordered_map<int, int> mp;

    for (int i = 0; i < size; i++)
    {
        mp[arr[i]]++;     //making hash table
    }

    for (auto i = mp.begin(); i != mp.end(); i++)
    {

        minh.push(make_pair(i->second, i->first));       //pushing map into minh

        if (minh.size() > k)
        {
            minh.pop();
        }
    }

    while (minh.size() >0)
    {
        
        pair<int, int> top = minh.top();

        cout<<top.second<<" ";

        minh.pop();
    }
}
