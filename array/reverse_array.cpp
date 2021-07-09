#include <iostream> 
using namespace std;

int main()

{

    int n, i, j, temp;
    cin >> n;

    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    j = n - 1;

    for (i = 0; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
