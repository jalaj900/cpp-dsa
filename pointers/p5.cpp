//pointer to pointer

#include <iostream>
using namespace std;

int main()
{
    int x = 5;
    int *p;
    p = &x;
    *p = 6;

    int **q; // pointer to pointer p which stores  the address of p

    q = &p;

    int ***r = &q; 

    cout << *p << endl;   //6
    cout << *q << endl;   //some address  (let it be 100)
    cout << **q << endl;  //6
    cout << **r << endl;  //some address (this will be also 100)
    cout << ***r << endl; //6

    ***r = 10;
    cout << x << endl; //10

    **q = *p + 2;
    cout << x << endl; //12
}