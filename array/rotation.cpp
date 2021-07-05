//rotation of element 
#include <iostream>
using namespace std;


void shift_left(int arr[],int n){
  int temp=arr[0];
  for (int i=1;i<n;i++){
    arr[i]=arr[i+1];
  }
  arr[0]=temp;
}


void shift_right(int arr[],int n){
  int temp=arr[n-1];
  for (int i=n-1;i>0;i++){
    arr[i]=arr[i-1];
  }
  arr[0]=temp;
}



int main() {

  int n;
  cin>>n;
  
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  shift_left(arr,  n);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  shift_right(arr,  n);

  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
return 0;
}