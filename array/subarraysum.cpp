//sum of largest sub array

//kadanes algo
//tc = O(n)

#include <iostream>
using namespace std;

int max_sum(int arr[],int n){
  int maxsum=0;
  int currsum=0;
  for (int i=0;i<n;i++){
    currsum=currsum+arr[i];
    if(currsum>maxsum){
      maxsum=currsum;
    }
    if (currsum<0){
      currsum=0;
    }
  }
  return maxsum;
}

int main() {

  int n;
  cin>>n;
  int arr[n];
  for (int i=0;i<n;i++){
    cin >> arr[i];

  }
  cout<<max_sum(arr,n)<<endl;

  return 0;
}