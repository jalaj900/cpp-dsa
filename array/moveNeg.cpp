//move negative elements to one side of aaray 
#include <bits/stdc++.h>
using namespace std;

void sort(int arr[], int l,int r){
   
  while(l<=r)
  {
    // left is + and right is +
    if (arr[l]>0 && arr[r]>0)
    {
      r--;
    }
    //left is - and right is -
    else if (arr[l]<0 && arr[r]<0)
    
    {
     l++; 
    }
 
     //left is + and right is -
    //swap right and left 
    //and l++ and r--
    else if(arr[l]>0 && arr[r]<0)
    {
      int temp =arr[l];
      arr[l]=arr[r];
      arr[r]=temp;
      l++;
      r--;
    }
  
  
    //left is + and right is +
    else  if (arr[l]>0  && arr[r]>0)
    {
      r--;
    }
    else
    {
    r--;
    l++;
    }

  }


}
 

int main() {
  int n,arr[n];
  cin >>n;
  for (int i=0;i<n;i++){
    cin>> arr[i];
  }
sort(arr,0,n-1);
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";

  }
}