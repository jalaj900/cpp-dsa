//pointer arithmetic

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int *p = &a;

    cout << p << endl; // let p=100

    cout << p + 1 << endl; // hence p+1 =104 as size p is int type so 4 bytes will be added

    cout << "address p is " << p << endl;
    cout << "value at address p" << *p << endl;

    cout<< endl; 
    
    cout << "address p is " << p+1 << endl;
    cout << "value at address p" << *(p+1) << endl;
}