// pointer types , void pointer , pointer arithmetics

#include <iostream>
using namespace std ;

int main()
{
    //void pointer  
    int a=1025;
    int *p;
    p=&a;

    cout <<"address "<<p;
    cout<<endl<<"value"<<*p<<endl;

    void *p0;
    p0=p;

    cout<<"address "<<p0<<endl;
    //cout<<"address"<<p0+1; not possible 
}