//pointers are varible that stores the address of another variable

//p -> address
//*p -> value at address pointed by p
#include <iostream>
using namespace std;

int main()
{
    int a=10;
    int *p;
    p=&a; //&a =address of a

    cout<<p<<endl;  
    cout<<&a<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;   
    *p=8;    // this is called as dereferencing
    cout<<a<<endl;


}