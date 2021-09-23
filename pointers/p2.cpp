#include <iostream>
using namespace std;

int main()
{
    int a;
    int *p;  //int* p - this will also work
    a = 10;
    p = &a; //&a =address of a

    cout << "address of p is " << p << endl;
    cout << "value at p is " << *p << endl;

    int b = 0;

    *p = b; // value will be modified only not the address

    cout<<endl;
    cout << "address of p is " << p << endl;
    cout << "value at p is " << *p << endl;
}