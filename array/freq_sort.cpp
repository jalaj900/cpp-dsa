//sort element of array on basic of their frequency


#include <bits/stdc++.h> 
using namespace std;
typedef multimap<int, int> MapType;
int main()
{
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    map<int, int> mp;

    for (int i = 0; i < N; i++)
    {
        if (mp.find(a[i]) != mp.end())
        {
            mp[a[i]]++;
        }

        else
        {

            mp[a[i]] = 1;
        }
    }

    multimap<int, int> mp2;
    map<int, int>::iterator it;

    for (it = mp.begin(); it != mp.end(); it++)
    {
        mp2.insert(MapType::value_type(it->second, it->first));
    }

    map<int, int>::reverse_iterator itr;

    for (itr = mp2.rbegin(); itr != mp2.rend(); itr++)
    {
        for (int i = 0; i < itr->first; i++)
            cout << itr->second << "\t";
    }

    return 0;
